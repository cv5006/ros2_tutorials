import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    # gazebo
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch'), '/gazebo.launch.py']),
             )

    robot_description_path = os.path.join(
        get_package_share_directory('ros2_control_demo_robot'),
        'description',
        'rrbot_system_position_only.urdf.xacro')
    print(robot_description_path)

    return LaunchDescription([
        # gazebo
    ])
