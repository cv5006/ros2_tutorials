# 0. Import Modules and Declare Constants
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from action_tutorial.action import Move
from std_msgs.msg import Int16
from std_srvs.srv import SetBool
from math import copysign
from time import sleep

NODE_NAME = 'mover'
MOTOR_TOPIC_NAME = 'motor'
SERVICE_NAME = 'run'
ACTION_NAME = 'move'
PARAMETER_NAME = 'step'

# 1. Define Node  
class MoveServer(Node):

    # 1.1. Define Constructor
    def __init__(self):
        super().__init__(NODE_NAME)

        self.step = 0
        
        # 1.1.1. Create Pub/Sub, Service Client, Action Server and Parameter
        self.pub = self.create_publisher(Int16, MOTOR_TOPIC_NAME, 10)
        self.cli = self.create_client(SetBool, SERVICE_NAME)
        self.act_srv = ActionServer(self, Move, ACTION_NAME, self.exe_callback)
        self.declare_parameter(PARAMETER_NAME)

    # 1.2. Define Execution Callback
    def exe_callback(self, hgoal):
        # 1.2.1. Call service to stop sine wave
        if self.cli.service_is_ready():
            off_flag = SetBool.Request()
            off_flag.data = False            
            self.cli.call_async(off_flag)

        # 1.2.2. Declare interface instances
        msg = Int16()
        feedback_msg = Move.Feedback()
        result_msg = Move.Result()
        goal = hgoal.request.destination

        # 1.2.3. Execute action!
        step_size = self.get_parameter(PARAMETER_NAME).get_parameter_value().integer_value + 1 
        if 0 <= goal <= 180:
            self.get_logger().info('Move from: %d → to: %d' % (msg.data, goal))        
            
            i = 0
            while True:
                err = (msg.data - goal)                
                msg.data = msg.data - (err if abs(err) < step_size else int(copysign(1, err)) * step_size)
                
                self.pub.publish(msg)
                feedback_msg.footprint = msg.data
                hgoal.publish_feedback(feedback_msg)
                
                if err == 0: 
                    hgoal.succeed()
                    self.get_logger().info('Successed!')
                    break            
                elif i > 10:
                    hgoal.abort()
                    self.get_logger().info('Failed! Too far!')            
                    break
                else:
                    i = i + 1
                    sleep(0.1)

        else:
            hgoal.abort()
            self.get_logger().error('Goal is out of range!')
        
        result_msg.position = msg.data     
        return result_msg


# 2. Define Main Function
def main(args = None):
    rclpy.init(args = args)

    node = MoveServer()
    node.get_logger().info('Mover is running!')

    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown


# 3. Run Main function
if __name__ == '__main__':
    main()
