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

sudo apt install ros-foxy-desktop -y

sudo apt install -y python3-pip -y
pip3 install -U argcomplete -y

sudo apt install python3-colcon-common-extensions -y