import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16

class Follower(Node):

    def __init__(self):
        super().__init__('follower')
        self.pub = self.create_publisher(Int16, 'motor', 10)
        self.sub = self.create_subscription(Int16, 'sensor', self.sensor_callback, 10)        
    
    def sensor_callback(self, msg):        
        motor = Int16()
        motor.data = self.callib(msg.data)
        self.pub.publish(motor)
        self.get_logger().info('Sensor: %d → Motor: %d' % (msg.data, motor.data))        

    def callib(self, val):
        return int(val/1000*180)


def main(args = None):

    rclpy.init(args=args)

    node = Follower()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
