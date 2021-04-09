repo_path="$(dirname ${BASH_SOURCE[0]}})/.."

model_path=gazebo_tutorials/models
plugin_path=gazebo_tutorials/plugins/build

export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:$repo_path/$model_path
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:$repo_path/$plugin_path