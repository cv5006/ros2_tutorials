#include "serial_receiver/serial_receiver.h"

#include <iostream>

using namespace std;
using namespace rclcpp;
using namespace chrono_literals;

SerialReceiver::SerialReceiver() : Node("serial_receiver")
{
    serial_.Begin("/dev/ttyS3", 115200);
    /* std::bind ? */
    timer_ = this->create_wall_timer(1s, bind(&SerialReceiver::TimerCallback, this));
    
}

SerialReceiver::~SerialReceiver()
{
    serial_.Close();
}

void SerialReceiver::TimerCallback()
{
    gets();
}

void SerialReceiver::gets(){
    char rx;    
    serial_.Read(&rx);
    cout << signed(rx) << endl;    
}

int main(int argc, char* argv[])
{
    init(argc, argv);
    spin(make_shared<SerialReceiver>());
    shutdown();
    
    return 0;
}