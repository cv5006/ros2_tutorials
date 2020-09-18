import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16
from std_srvs.srv import SetBool

from math import sin

node_name = 'sine_wave'

class SineWave(Node):

    def __init__(self):
        super().__init__(node_name)

        self.enable = True
        self.timer_period = 0.05
        self.dt = 0.0

        self.pub = self.create_publisher(Int16, 'motor', 10)
        self.tim = self.create_timer(self.timer_period, self.timer_callback)

        self.srv = self.create_service(SetBool, node_name+'/run', self.srv_callback)
        

    
    def timer_callback(self):
        if self.enable:
            self.dt = self.dt + self.timer_period

            motor = Int16()
            motor.data = int( 90*sin(1.57*self.dt)+90 )

            self.pub.publish(motor)
            self.get_logger().info('Motor: %d' % motor.data)


    def srv_callback(self, request, response):
        if request.data:
            self.enable = True            
            message = "Sine wave enabled"
        else:
            self.enable = False            
            message = "Sine wave disabled"

        response.success = self.enable
        response.message = message
        self.get_logger().info(message)
        return response



def main(args = None):

    rclpy.init(args=args)

    node = SineWave()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
