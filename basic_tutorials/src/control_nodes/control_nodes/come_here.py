import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16


class ComeHere(Node):

    def __init__(self):
        super().__init__('come_here')
        print('ok')


def main(args = None):
    rclpy.init(args = args)

    node = ComeHere()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown

if __name__ == '__main__':
    main()
