import rclpy
from rclpy.node import Node
import torch
from .network import Network

from dataglove_msgs.msg import VMG30Data


class RealTimeClassifier(Node):
    def __init__(self):
        super().__init__('real_time_classifier')
        self.get_logger().info('Real Time Classifier Node has been started.')
        self.get_logger().info(f'{torch.__version__}')
        
        self.window = torch.zeros((100, 31), dtype=torch.float32)
        
        self.net = Network()  
        self.net.load_state_dict(torch.load('/home/feld/ros2_ws/src/model/checkpoint.pt'))
        
        self.subscription = self.create_subscription(
            VMG30Data,  # Replace with the actual message type you expect
            '/sensor',  # Replace with the actual topic name
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
        print(self.window.shape)

        self.inference()


    def inference(self):
        window_tensor = self.window.unsqueeze(0).unsqueeze(0)
        # print(f'Window tensor shape: {window_tensor.shape}')
        self.net.eval()  
        with torch.no_grad():
            output = self.net(window_tensor)
            # self.get_logger().info(f'output: {output}')
            # Assuming the output is a tensor of class probabilities
            predicted_class = torch.argmax(output, dim=1).item()
            self.get_logger().info(f'Predicted class: {predicted_class}')



def main(args=None):
    rclpy.init(args=args)

    data_saver = RealTimeClassifier()

    rclpy.spin(data_saver)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    data_saver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()