repo_path=~/dev # Modify to your base path

model_path=ros2_tutorials/gazebo_tutorials/models
plugin_path=ros2_tutorials/gazebo_tutorials/plugins/build

export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:$repo_path/$model_path
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:$repo_path/$plugin_path