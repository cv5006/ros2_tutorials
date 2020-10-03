#include "serial_io/serial_io.h"

using namespace std;
using namespace rclcpp;
using namespace chrono_literals;

#define UNUSED(x) (void)(x)

using std::placeholders::_1;

SerialIO::SerialIO() : Node("serial_io")
{    
    timer_ = this->create_wall_timer(100ms, bind(&SerialIO::TimerCallback, this));
    pub_ = this->create_publisher<msg_t>("sensor", 10);
    sub_ = this->create_subscription<msg_t>("motor", 10, bind(&SerialIO::UpdateMotorAngle, this, _1));
    
    this->declare_parameter<string>("serial_port", "/dev/ttyS3");    
    this->get_parameter("serial_port", port_name_);

    serial_.Begin(port_name_, 115200);    
}

SerialIO::~SerialIO()
{
    serial_.End();
}

void SerialIO::TimerCallback()
{
    int rx_data;

    serial_.WriteInt(motor_angle_);    
    serial_.ReadInt(rx_data);

    RCLCPP_INFO(this->get_logger(), "%d : %d", motor_angle_, rx_data);

    counter_++;
}

void SerialIO::UpdateMotorAngle(const msg_t::SharedPtr msg)
{
    motor_angle_ = msg->data;
}


int main(int argc, char* argv[])
{
    init(argc, argv);
    auto node = make_shared<SerialIO>();    
    spin(node);    
    shutdown();    
    return 0;
}