/*
 * serial_reciever.h
 * 
 */
#ifndef SERIAL_RECEIVER_SERIAL_RECIEVER_H_
#define SERIAL_RECEIVER_SERIAL_RECIEVER_H_

#include <chrono>
#include <functional>
#include <sstream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "basic_tutorial_interfaces/srv/set_home.hpp"

#include "simple_serial.h"

class SerialReceiver : public rclcpp::Node
{
public:
    SerialReceiver();
    ~SerialReceiver();

    void gets();

private:
    std::string port_name_;
    char counter_ = 0;
    void TimerCallback();


    SimpleSerial serial_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Service<basic_tutorial_interfaces::srv::SetHome>::SharedPtr srv_;
    // cannot refer member funcsion as srv callback, but static member. why?
    static void SetHome(const std::shared_ptr<basic_tutorial_interfaces::srv::SetHome::Request>  req,
                       std::shared_ptr<basic_tutorial_interfaces::srv::SetHome::Response> res)
            {
                std::cout << "srv called!" << std::endl;
            }
};

/*
void SetHome(const std::shared_ptr<basic_tutorial_interfaces::srv::SetHome::Request>  req,
                   std::shared_ptr<basic_tutorial_interfaces::srv::SetHome::Response> res)
            {
                std::cout << "srv called!" << std::endl;
            }
*/
#endif