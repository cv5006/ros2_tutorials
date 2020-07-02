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
    
};



#endif