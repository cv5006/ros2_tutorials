from launch import LaunchDescription
from launch_ros.actions import Node

from ament_index_python import get_package_share_directory
import xacro


pkg_dir = get_package_share_directory("mypkg")
xacro_path  = f"{pkg_dir}/xacro/myrobot_urdf.xacro"
config_path = f"{pkg_dir}/config/myrobot.yaml"


def generate_launch_description():
    # Robot description
    robot_description = {
        "robot_description": xacro.process_file(xacro_path).toxml()
    }

    robot_state_pub_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
    )


    # Controls
    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_description, config_path],
        output="both",
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    forward_position_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["forward_position_controller"],
    )


    # Launch
    nodes = [
        control_node,
        robot_state_pub_node,
        joint_state_broadcaster_spawner,
        forward_position_controller_spawner
    ]

    return LaunchDescription(nodes)