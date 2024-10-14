#ifndef MY_CONTROLLER_HPP_
#define MY_CONTROLLER_HPP_

#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "control_msgs/msg/joint_trajectory_controller_state.hpp"
#include "controller_interface/controller_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "rclcpp/duration.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp/timer.hpp"
#include "rclcpp_lifecycle/lifecycle_publisher.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"

namespace mycontrol
{
class MyController : public controller_interface::ControllerInterface
{
public:
  CONTROLLER_INTERFACE_PUBLIC
  MyController();

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::InterfaceConfiguration command_interface_configuration() const override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::InterfaceConfiguration state_interface_configuration() const override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::return_type update(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_init() override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_configure(
    const rclcpp_lifecycle::State & previous_state) override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_activate(
    const rclcpp_lifecycle::State & previous_state) override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_deactivate(
    const rclcpp_lifecycle::State & previous_state) override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_cleanup(
    const rclcpp_lifecycle::State & previous_state) override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_error(
    const rclcpp_lifecycle::State & previous_state) override;

  CONTROLLER_INTERFACE_PUBLIC
  controller_interface::CallbackReturn on_shutdown(
    const rclcpp_lifecycle::State & previous_state) override;

protected:
};

}  // namespace mycontrol

#endif  // MY_CONTROLLER_HPP_