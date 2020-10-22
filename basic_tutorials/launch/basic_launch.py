from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='hw_nodes',
            node_executable='serial_io',
            node_namespace='tutorial',
            arguments=["/dev/ttyS3"]
        ),

        Node(
            package='control_nodes',
            node_executable='follower',
            node_namespace='tutorial'
        ),

        Node(
            package='control_nodes',
            node_executable='mover',
            node_namespace='tutorial',
            parameters=[{"step":10}],
            emulate_tty=True,
            output="screen"
        )
    ])