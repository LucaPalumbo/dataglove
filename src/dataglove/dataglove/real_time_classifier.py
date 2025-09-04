import rclpy
from rclpy.node import Node
import torch
from .network import Network
import os

from dataglove_msgs.msg import VMG30Data


class RealTimeClassifier(Node):
    def __init__(self):
        super().__init__('real_time_classifier')
        self.get_logger().info('Real Time Classifier Node has been started.')
        self.get_logger().info(f'{torch.__version__}')

        self.declare_parameter('continual', False)
        continual = self.get_parameter('continual').value
        path = "/home/feld/ros2_ws/src/nn/"

        self.window = torch.zeros((200, 31), dtype=torch.float32)
        
        self.net = Network(output_classes=6)
        if continual:
            self.get_logger().info('Loading model with 6 classes.')
            self.net.classifier.add_task(output_classes=2)  # Assuming 2 classes of continual learning
            path = os.path.join(path, 'distillated_checkpoint.pt')
        else:
            path = os.path.join(path, 'checkpoint.pt')
        self.net.load_state_dict(torch.load(path))

        
        self.subscription = self.create_subscription(
            VMG30Data,  
            '/sensor', 
            self.classify_data,
            10)
        
        # Initialize your classifier here
        # For example, load a pre-trained model or set up parameters

    def classify_data(self, data):
        sensors = [ d / 1000 * 2 - 1 for d in data.sensors.tolist() ]
        quat_hand = data.quat_hand.tolist()
        quat_forearm = data.quat_forearm.tolist()
        concatenated_data = sensors + quat_hand + quat_forearm
        # convert this values to tenor
        tensor_data = torch.tensor(concatenated_data, dtype=torch.float32)
        # print(f'Concatenated data: {tensor_data.shape}')
        # Add the new data to the window
        self.window = torch.cat((self.window[1:], tensor_data.unsqueeze(0)), dim=0)

        self.inference()


    def inference(self):
        labels = ["rest", "bottle", "pen", "phone", "mouse", "glasses"]
        window_tensor = self.window.unsqueeze(0).unsqueeze(0)
        self.net.eval()  
        with torch.no_grad():
            output = self.net(window_tensor)
            # Output is a tensor of class probabilities
            predicted_class = torch.argmax(output, dim=1).item()
            self.get_logger().info(f'Predicted class: {predicted_class}: {labels[predicted_class]}')



def main(args=None):
    rclpy.init(args=args)

    rt_classifier = RealTimeClassifier()

    rclpy.spin(rt_classifier)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    rt_classifier.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()