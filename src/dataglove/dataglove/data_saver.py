import rclpy
from rclpy.node import Node

from std_msgs.msg import String, Int32
from dataglove_msgs.msg import VMG30Data
import os


class DataSaver(Node):

    def __init__(self):
        super().__init__('data_saver')
        self.get_logger().info('Data Saver Node has been started.')
        # self.file_name = '/home/feld/ros2_ws/datasets/test/' + 'data_' + str(self.get_clock().now().nanoseconds) + '.txt'
        self.dir_name = "/home/feld/ros2_ws/datasets/new_dataset/"
        self.object_name = "pen" # CHANGE THIS TO THE OBJECT YOU ARE SAVING DATA FOR
        os.makedirs(os.path.join(self.dir_name, self.object_name), exist_ok=True)
        index = 0 
        while os.path.exists( os.path.join(self.dir_name, self.object_name, str(index) + '.txt') ):
            index += 1
        self.file_name = os.path.join(self.dir_name, self.object_name, str(index) + '.txt')
        self.get_logger().info(f'Saving data to file: {self.file_name}')
        


        self.subscription = self.create_subscription(
            VMG30Data,
            '/sensor',
            self.data_callback,
            100)
        
        self.test_subscription = self.create_subscription(
            Int32,
            '/test',
            self.test_callback,
            10)
        
        # prevent unused variable warning
        self.test_subscription
        self.subscription  

    def data_callback(self, msg):
        # self.get_logger().info('I heard: "%s"' % msg.data)
        # read data from the VMG30Data message
        packet_tick = msg.packet_tick
        time = msg.time
        sensors = msg.sensors.tolist()  
        quat_hand = msg.quat_hand.tolist()
        quat_forearm = msg.quat_forearm.tolist()

        # Converti le liste in stringhe separate da virgole
        sensors_str = ",".join(map(str, sensors))
        quat_hand_str = ",".join(map(str, quat_hand))
        quat_forearm_str = ",".join(map(str, quat_forearm))
        
        # store to a file 
        # self.get_logger().info(f'sensors: {sensors.tolist()}')
        with open(self.file_name, 'a') as f:
            f.write(f"{packet_tick}, {time}, {sensors_str}, {quat_hand_str}, {quat_forearm_str}\n")

        self.get_logger().info(f'Saved data: {sensors}')

    def test_callback(self, msg):
        self.get_logger().info('Test callback received: "%s"' % msg.data)
        # save test data to a file
        with open('test_data.txt', 'a') as f:
            f.write(f"{msg.data}\n")


def main(args=None):
    rclpy.init(args=args)

    data_saver = DataSaver()

    rclpy.spin(data_saver)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    data_saver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()