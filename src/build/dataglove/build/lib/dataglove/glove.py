from rclpy.node import Node
import rclpy
from std_msgs.msg import Float32MultiArray
from dataglove_msgs.msg import VMG30Data
from .vmg30 import *

class Glove(Node):
    def __init__(self, node_name='glove_reader'):
        super().__init__(node_name)
        self.glove_data_publisher = self.create_publisher(VMG30Data, '/sensor', 10)

        self.timer = self.create_timer(0.1, self.read_glove_data)
        # self.device = VMG30('/dev/ttyUSB0')

        self.get_logger().info('Starting reading from VMG30 glove...')


    def read_glove_data(self):
        self.get_logger().info('Reading data from glove...')
        # if self.device.read_stream() == 0 and self.device.is_new_packet_available():
            # get all the data available from the glove
            # data = self.device


def main():
    rclpy.init()
    node = Glove()
    rclpy.spin(node)


    node.destroy_node()
    rclpy.shutdown()

