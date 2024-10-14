#include "mypkg/myhardware.hpp"

namespace mycontrol
{
CallbackReturn MyHardware::on_init(const hardware_interface::HardwareInfo & info)
{
    if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS) {
        return CallbackReturn::ERROR;
    }

    return CallbackReturn::SUCCESS;
}


std::vector<hardware_interface::StateInterface> MyHardware::export_state_interfaces()
{
    std::vector<hardware_interface::StateInterface> state_interfaces;

    return state_interfaces;
}


std::vector<hardware_interface::CommandInterface> MyHardware::export_command_interfaces()
{
    std::vector<hardware_interface::CommandInterface> command_interfaces;
    
    return command_interfaces;
}


return_type MyHardware::read(const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
    return return_type::OK;
}

return_type MyHardware::write(const rclcpp::Time &, const rclcpp::Duration &)
{
    return return_type::OK;
}

}  // namespace mycontrol

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(
mycontrol::MyHardware, hardware_interface::SystemInterface)