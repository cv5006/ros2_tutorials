import rclpy
from rclpy.node import Node
import curses

from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3

class Keyops(Node):
    def __init__(self):
        super().__init__('keyops')
        self.publisher_ = self.create_publisher(Twist, '/demo/cmd_demo', 10)
        
        self.cmd_ = Twist()
        self.vel = 0.0
        self.steer = 0.0        
        self.acc = 0.1

        # initialize curses screen
        self.screen_ = curses.initscr() # get the curses screen window
        curses.noecho()                 # turn off input echoing    
        curses.cbreak()                 # respond to keys immediately (don't wait for enter)        
        self.screen_.keypad(True)       # map arrow keys to special values
        
        # NOTE: print doesn't work with curses, use addstr instead
        self.screen_.addstr(0,0,'key')  

    def control(self):
        char = self.screen_.getch()
        
        if char == curses.KEY_RIGHT:
            self.screen_.addstr(1, 0, '→')
            self.steer = self.steer - self.acc
        elif char == curses.KEY_LEFT:
            self.screen_.addstr(1, 0, '←')
            self.steer = self.steer + self.acc
        elif char == curses.KEY_UP:
            self.screen_.addstr(1, 0, '↑')
            self.steer = 0.0
            self.vel = self.vel + self.acc
        elif char == curses.KEY_DOWN:
            self.screen_.addstr(1, 0, '↓')
            self.steer = 0.0
            self.vel = self.vel - self.acc
        elif char == 115: # s
            self.screen_.addstr(1, 0, '◎')
            self.steer = 0.0
            self.vel = 0.0            
        elif char == 113: # q
            exit()

        self.cmd_.linear.x = self.vel
        self.cmd_.angular.z = self.steer

        self.publisher_.publish(self.cmd_)
        
    def __del__(self):
        curses.nocbreak()
        self.screen_.keypad(False)
        curses.echo()
        curses.endwin() # restore terminal
        

def main(args=None):
    rclpy.init(args=args)

    keyops = Keyops()
    
    rclpy.spin_once(keyops, timeout_sec=0)
    while(rclpy.ok()):
        keyops.control()

    keyops.destroy_node()
    
    rclpy.shutdown()

if __name__ == '__main__':    
    main()    
