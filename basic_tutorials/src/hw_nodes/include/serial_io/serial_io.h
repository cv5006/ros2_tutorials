/*
 * serial_io.h
 * 
 */
#ifndef SERIAL_IO_H_
#define SERIAL_IO_H_

#include <chrono>
#include <functional>
#include <sstream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16.hpp"

#include "simple_serial.h"

typedef std_msgs::msg::Int16 msg_t;

class SerialIO : public rclcpp::Node
{
public:
    SerialIO();
    ~SerialIO();

private:
    std::string port_name_;
    size_t counter_ = 0;
    int motor_angle_ = 0;    

    void TimerCallback();
    void UpdateMotorAngle(const msg_t::SharedPtr msg);
    
    SimpleSerial serial_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<msg_t>::SharedPtr pub_;
    rclcpp::Subscription<msg_t>::SharedPtr sub_;

};

#endif