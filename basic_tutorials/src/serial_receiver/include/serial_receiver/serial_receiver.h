/*
 * serial_reciever.h
 * 
 */
#ifndef SERIAL_RECEIVER_SERIAL_RECIEVER_H_
#define SERIAL_RECEIVER_SERIAL_RECIEVER_H_

#include <chrono>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "linux_serial.h"

class SerialReceiver : public rclcpp::Node
{
public:
    SerialReceiver();
    ~SerialReceiver();

    void gets();

private:
    void TimerCallback();

    LinuxSerial serial_;
    rclcpp::TimerBase::SharedPtr timer_;
    
};



#endif