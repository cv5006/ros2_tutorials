// Copyright 2023 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mypkg/mycontroller.hpp"

#include <stddef.h>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/qos.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"

using config_type = controller_interface::interface_configuration_type;

namespace mycontrol
{
MyController::MyController() : controller_interface::ControllerInterface() {}


controller_interface::CallbackReturn MyController::on_init()
{

    return CallbackReturn::SUCCESS;
}


controller_interface::InterfaceConfiguration MyController::command_interface_configuration() const
{
    controller_interface::InterfaceConfiguration conf = {config_type::INDIVIDUAL, {}};
    
    return conf;
}


controller_interface::InterfaceConfiguration MyController::state_interface_configuration() const
{
    controller_interface::InterfaceConfiguration conf = {config_type::INDIVIDUAL, {}};

    return conf;
}


controller_interface::CallbackReturn MyController::on_configure(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}


controller_interface::CallbackReturn MyController::on_activate(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}


controller_interface::return_type MyController::update(const rclcpp::Time & time, const rclcpp::Duration & period)
{

    return controller_interface::return_type::OK;
}


controller_interface::CallbackReturn MyController::on_deactivate(const rclcpp_lifecycle::State &)
{
    release_interfaces();
    return CallbackReturn::SUCCESS;
}


controller_interface::CallbackReturn MyController::on_cleanup(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}


controller_interface::CallbackReturn MyController::on_error(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}


controller_interface::CallbackReturn MyController::on_shutdown(const rclcpp_lifecycle::State &)
{
    return CallbackReturn::SUCCESS;
}

}  // namespace mycontrol

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
mycontrol::MyController, controller_interface::ControllerInterface)