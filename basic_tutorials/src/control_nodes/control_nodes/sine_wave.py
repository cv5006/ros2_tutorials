import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16

from math import sin

class SineWave(Node):

    def __init__(self):
        super().__init__('sine_wave')
        self.pub = self.create_publisher(Int16, 'motor', 10)
        self.tim = self.create_timer(self.timer_period, self.timer_callback)
        
        timer_period = 0.05
        dt = 0.0
    
    def timer_callback(self):
        self.dt = self.dt + self.timer_period

        motor = Int16()
        motor.data = int( 90*sin(1.57*self.dt)+90 )

        self.pub.publish(motor)
        self.get_logger().info('Motor: %d' % motor.data)


def main(args = None):

    rclpy.init(args=args)

    node = SineWave()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
