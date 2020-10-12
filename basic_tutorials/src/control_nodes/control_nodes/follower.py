# 0. Import Modules and Declare Constants
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16

NODE_NAME = 'follower'
MOTOR_TOPIC_NAME = 'motor'
SENSOR_TOPIC_NAME = 'sensor'

# 1. Define Node
class Follower(Node):    
    # 1.1. Define Constructor
    def __init__(self):
        
        # 1.1.1. Initialize Node
        super().__init__(NODE_NAME)
        
        # 1.1.2. Create publisher/subscriber instance
        self.pub = self.create_publisher(Int16, MOTOR_TOPIC_NAME, 10)
        self.sub = self.create_subscription(Int16, SENSOR_TOPIC_NAME, self.sensor_callback, 10)        
    

    # 1.2. Define Subscriber Callback Method
    def sensor_callback(self, msg):
        # 1.2.1. Create message instance to publish
        motor = Int16()

        # 1.2.2. Assing data to message
        motor.data = int(msg.data/1000*180)

        # 1.2.3. Publish message
        self.pub.publish(motor)
        
        # 1.2.4. Print result
        self.get_logger().info('Sensor: %d → Motor: %d' % (msg.data, motor.data))        


# 2. Define Main Function
def main(args = None):

    # 2.1. Initialize RCLPY
    rclpy.init(args=args)

    # 2.2. Create and node instance
    node = Follower()
    node.get_logger().info("Node is ready!")

    # 2.3. Spin the node and handle exception
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("WTF")

    # 2.4. Destory node and shutdown RCLPY
    node.destroy_node() # Note this is optional
    rclpy.shutdown()

# 3. Run Main function
if __name__ == '__main__':
    main()
