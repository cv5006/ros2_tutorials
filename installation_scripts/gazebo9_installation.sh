# http://gazebosim.org/tutorials?cat=install&tut=install_ubuntu&ver=9.0

sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'

wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -

sudo apt-get update

sudo apt-get install gazebo9 -y
sudo apt-get install libgazebo9-dev -y
sudo apt install ros-foxy-gazebo-ros-pkgs -y
