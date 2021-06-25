import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, ExecuteProcess, RegisterEventHandler
from launch.event_handlers import OnProcessExit
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

    doc = xacro.parse(open(urdf_file))
    xacro.process_doc(doc)
    robot_description = {'robot_description': doc.toxml()}

    # gazebo
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch'), '/gzserver.launch.py']),
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

    return LaunchDescription([
        gazebo,
        node_robot_state_publisher,
        spawn_entity,
    ])
