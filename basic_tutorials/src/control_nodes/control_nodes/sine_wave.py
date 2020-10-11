# 0. Import Modules and Declare Constants
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16
from std_srvs.srv import SetBool
from math import sin
from math import pi

NODE_NAME = 'sine_wave'
MOTOR_TOPIC_NAME = 'motor'
SERVICE_NAME = 'run'
PARAMETER_NAME = 'period'

# 1. Define Node  
class SineWave(Node):
    # 1.1. Define Constructor
    def __init__(self):
        super().__init__(NODE_NAME)

        # 1.1.1. Create class mebers
        self.enable = True
        self.timer_period = 0.1
        self.wave_time = 0.0

        # 1.1.2. Create Timer, Publisher, Serive server and Parameter
        self.tim = self.create_timer(self.timer_period, self.timer_callback)
        self.pub = self.create_publisher(Int16, MOTOR_TOPIC_NAME, 10)
        self.srv = self.create_service(SetBool, SERVICE_NAME, self.srv_callback)        
        self.declare_parameter(PARAMETER_NAME)


    # 1.2. Define Timer Callback Method
    def timer_callback(self):
        if self.enable:
            # 1.2.1. Create message instance to publish
            motor = Int16()
            
            # 1.2.2. Get parameter            
            period = self.get_parameter(PARAMETER_NAME).get_parameter_value().double_value

            # 1.2.3. Get sine wave point
            self.wave_time = self.wave_time + self.timer_period
            motor.data = int(90*(sin(2*pi*period*self.wave_time)+1))

            # 1.2.4. Publish message and print result
            self.pub.publish(motor)
            self.get_logger().info('Motor: %d' % motor.data)


    # 1.3. Define Service Callback Method
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


# 2. Define Main Function
def main(args = None):
    rclpy.init(args=args)

    node = SineWave()
    rclpy.spin(node)    

    node.destroy_node()
    rclpy.shutdown()


# 3. Run Main function
if __name__ == '__main__':
    main()
