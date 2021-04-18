# https://docs.ros.org/en/foxy/Installation/Linux-Install-Debians.html

sudo apt update
sudo apt install locales -y
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8



sudo apt update
sudo apt install curl gnupg2 lsb-release -y
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -

sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'

sudo apt update

# ROS2 desktop
sudo apt install ros-foxy-desktop -y

# argcomplete
sudo apt install -y python3-pip -y
pip3 install -U argcomplete -y

# Build tool
sudo apt install python3-colcon-common-extensions -y

# ROS2 Control
sudo apt install ros-foxy-ros2-control ros-foxy-ros2-controllers -y

# Some dependencies
sudo apt install ros-foxy-realtime-tools ros-foxy-xacro ros-foxy-angles -y