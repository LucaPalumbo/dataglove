import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from dataglove_msgs.msg import VMG30Data


class DataSaver(Node):

    def __init__(self):
        super().__init__('data_saver')
        self.get_logger().info('Data Saver Node has been started.')
        self.subscription = self.create_subscription(
            VMG30Data,
            '/sensor',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


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