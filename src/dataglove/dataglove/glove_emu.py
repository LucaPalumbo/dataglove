from rclpy.node import Node
import rclpy
from std_msgs.msg import Float32MultiArray, Int32
from dataglove_msgs.msg import VMG30Data
from .vmg30 import *
from threading import Event, Thread
import numpy as np
import pandas as pd

class Glove(Node):
    def __init__(self, node_name='glove'):
        super().__init__(node_name)
        self.glove_data_publisher = self.create_publisher(VMG30Data, '/sensor', 100)

        self.timer_period = 0.2
        self.timer = self.create_timer(self.timer_period, self.publish_glove_data)

        self.df = pd.read_csv('/home/feld/ros2_ws/src/model/dataset/test/bottle/data_1750411170490387365.txt')
        self.row_sent = 0



    def publish_glove_data(self):
        print(f'Publishing glove data: {self.df.shape}')
        if self.row_sent < self.df.shape[0]:
            row = self.df.iloc[self.row_sent]
            msg = VMG30Data()
            msg.packet_tick = int(row[0])
            msg.time = float(row[1])
            msg.sensors = np.array(row[2:25], dtype=np.float32)
            msg.rpy_hand = np.array(row[25:28], dtype=np.float32)
            msg.quat_hand = np.array(row[28:32], dtype=np.float32)
            msg.rpy_forearm = np.array(row[32:35], dtype=np.float32)
            msg.quat_forearm = np.array(row[35:39], dtype=np.float32)

            self.glove_data_publisher.publish(msg)
            self.row_sent += 1
        else:
            self.get_logger().info('All data sent, stopping the timer.')
            self.timer.cancel()
        
        



def main():
    rclpy.init()
    node = Glove()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass


    node.destroy_node()
    rclpy.shutdown()

