#include "serial_receiver/serial_receiver.h"

#include <iostream>

using namespace std;
using namespace rclcpp;
using namespace chrono_literals;

SerialReceiver::SerialReceiver() : Node("serial_receiver")
{    
    /* std::bind ? */
    timer_ = this->create_wall_timer(500ms, bind(&SerialReceiver::TimerCallback, this));
    //srv_ = this->create_service<basic_tutorial_interfaces::srv::SetHome>("set_home", &SerialReceiver::SetHome);
    this->declare_parameter<string>("serial_port", "/dev/ttyS3");
    this->get_parameter("serial_port", port_name_);
    serial_.Begin(port_name_, 115200);
    serial_.Flush();
}

SerialReceiver::~SerialReceiver()
{
    serial_.Close();
}

void SerialReceiver::TimerCallback()
{
    gets();    
}

void SerialReceiver::gets()
{     
    string a = "";
    serial_.Read(a);
    cout << "Read: " << (int)a.c_str()[0] << endl;    
}

int main(int argc, char* argv[])
{    
    init(argc, argv);
    spin(make_shared<SerialReceiver>());
    shutdown();
    
    return 0;
}