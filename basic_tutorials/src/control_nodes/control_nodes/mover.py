import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from action_tutorial.action import Move
from std_msgs.msg import Int16
from std_srvs.srv import SetBool

from time import sleep

class MoveServer(Node):
    
    def __init__(self):
        super().__init__('mover')
        self.act_srv = ActionServer(
            self,
            Move,
            'move',
            self.exe_callback
        )

        self.cli = self.create_client(SetBool, 'sine_wave/run')

        self.pos = 0
        self.tol = 1
        

    def exe_callback(self, hgoal):
        if self.cli.service_is_ready():
            off_flag = SetBool.Request()
            off_flag.data = False
            self.cli.call_async(off_flag)

        feedback_msg = Move.Feedback()
        result_msg =  Move.Result()
        goal = hgoal.request.destination
        
        self.get_logger().info('Move from: %d → to: %d' % (self.pos, goal))
        
        i = 0
        while True:
            err = self.pos - goal
            
            self.pos = self.pos - int((err>0) - (err<0))
            feedback_msg.footprint = self.pos
            hgoal.publish_feedback(feedback_msg)
            sleep(0.01)
            
            if abs(err) <= self.tol : hgoal.succeed(); break
            if i > 100 :              hgoal.abort(); break
            
            i = i + 1
        
        result_msg.position = self.pos

        return result_msg



def main(args = None):
    rclpy.init(args = args)

    node = MoveServer()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown

if __name__ == '__main__':
    main()
