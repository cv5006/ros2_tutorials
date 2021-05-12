import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node

import xacro

def generate_launch_description():
    pkg_name = 'xacro_tutorial'
    robot_name = 'unibot'

    urdf_file = os.path.join(
        get_package_share_directory(pkg_name),
        'model',
        robot_name + '.xacro'
        )

    controller_config_file = os.path.join(
        get_package_share_directory(pkg_name),
        'config',
        'controllers.yaml'        
        )

    doc = xacro.parse(open(urdf_file))
    xacro.process_doc(doc)
    robot_description = {'robot_description': doc.toxml()}

    # gazebo
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch'), '/gazebo.launch.py']),
             )

    # spawn robot
    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', robot_name],
                        output='screen')


    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',        
        parameters=[
            robot_description
        ],
        output='screen'
    )


    # ros_control
    controller_manager = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[
            robot_description,
            controller_config_file
        ],
        output='screen'
    )

    return LaunchDescription([
        controller_manager,
        gazebo,
        node_robot_state_publisher,
        spawn_entity,
        
    ])
