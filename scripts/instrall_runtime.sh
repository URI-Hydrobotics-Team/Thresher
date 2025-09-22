#!/usr/bin/env bash
set -e

# Ensure script is run on Ubuntu 22.04
if [ "$(lsb_release -rs)" != "22.04" ]; then
    echo "This script is only supported on Ubuntu 22.04 (Jammy)."
    exit 1
fi

# Setup locale
sudo apt update && sudo apt install -y locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

# Add ROS 2 apt repo
sudo apt install -y software-properties-common curl
sudo add-apt-repository universe
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
    -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | \
    sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install ROS 2 Humble base
sudo apt update
sudo apt install -y ros-humble-ros-base python3-colcon-common-extensions

# Setup environment in .bashrc
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
echo "ROS 2 Humble base installation complete."
