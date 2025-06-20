from rclpy.node import Node
import rclpy
from std_msgs.msg import Float32MultiArray, Int32
from dataglove_msgs.msg import VMG30Data
from .vmg30 import *
import random
from threading import Event, Thread
import numpy as np
from time import sleep, time

class Glove(Node):
    def __init__(self, node_name='glove'):
        super().__init__(node_name)
        self.glove_data_publisher = self.create_publisher(VMG30Data, '/sensor', 100)
        self.test_data_publisher = self.create_publisher(Int32, '/test', 10)

        self.timer_period = 0.01  # 100 Hz
        self.timer = self.create_timer(self.timer_period, self.publish_glove_data)

        #self.timer = self.create_timer(0.1, self.read_glove_data)
        # self.test_timer = self.create_timer(0.1, self.publish_test)

        self.vmg = VMG30('/dev/ttyUSB0')
        self.vmg.open_device()
        self.vmg.send_start_packet(0x1)  # PKT_TYPE_QUAT_FINGER

        # Eventi di terminazione per i thread
        self.stop_event = Event()
        self.time_start = time()

        # Thread per la lettura continua dalla seriale
        self.read_thread = Thread(target=self.read_loop)
        # self.publish_thread = Thread(target=self.publish_loop)
        # self.test_thread = Thread(target=self.test_thread)

        # self.test_thread.start()
        self.read_thread.start()
        # self.publish_thread.start()


        self.get_logger().info('Starting reading from VMG30 glove...')

    # def test_thread(self):
    #     self.get_logger().info('Test thread started')

    def read_loop(self):
        """Thread dedicato alla lettura continua dalla seriale"""
        self.get_logger().info('Starting read loop...')
        while not self.stop_event.is_set():
            self.vmg.read_stream()

    # def publish_loop(self):
    #     """Thread dedicato alla pubblicazione periodica dei dati"""
    #     publish_period = 1.0 / 100.0  # 100 Hz - FINE TUNE THIS 

    #     while not self.stop_event.is_set():
    #         if self.vmg.is_new_packet_available():
    #             msg = VMG30Data()
    #             msg.time = time() - self.time_start
    #             # temp = self.vmg.sensors.astype(np.float32).tolist()
    #             # self.get_logger().info(f'Raw sensors data: {temp}')
    #             msg.sensors = self.vmg.sensors.astype(np.float32).tolist()
    #             msg.rpy_hand = self.vmg.rpy_hand.tolist()
    #             msg.quat_hand = self.vmg.quaternion_hand.tolist()
    #             msg.rpy_forearm = self.vmg.rpy_wrist.tolist()
    #             msg.quat_forearm = self.vmg.quaternion_wrist.tolist()

    #             self.glove_data_publisher.publish(msg)
    #             self.get_logger().info(f'sensors {msg.sensors}')
    #             self.vmg.reset_new_packet()

    #         sleep(publish_period)


    def publish_glove_data(self):
        if self.vmg.is_new_packet_available():
            msg = VMG30Data()
            msg.packet_tick = self.vmg.packet_tick
            msg.time = time() - self.time_start
            msg.sensors = self.vmg.sensors.astype(np.float32).tolist()
            msg.rpy_hand = self.vmg.rpy_hand.tolist()
            msg.quat_hand = self.vmg.quaternion_hand.tolist()
            msg.rpy_forearm = self.vmg.rpy_wrist.tolist()
            msg.quat_forearm = self.vmg.quaternion_wrist.tolist()

            self.glove_data_publisher.publish(msg)
            self.vmg.reset_new_packet()

    def destroy_node(self):
        """Chiusura ordinata di nodo e thread"""
        self.stop_event.set()
        self.read_thread.join()
        self.publish_thread.join()
        self.vmg.close_device()
        super().destroy_node()


    def publish_test(self):
        test_msg = Int32()
        test_msg.data = random.randint(0, 100)
        self.test_data_publisher.publish(test_msg)
        self.get_logger().info(f'Published test data: {test_msg.data}')

def main():
    rclpy.init()
    node = Glove()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass


    node.destroy_node()
    rclpy.shutdown()

