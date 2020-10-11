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
}

bool SerialIO::OpenPort(const char* port_name)
{
    error_t err = serial_.Begin(port_name, 115200);

    if(err == 22){ err = 0;} // IDK why error 22 rises even when everything is fine!

    if(err == 0){
        RCLCPP_INFO(this->get_logger(), "Successfully opened port: %s", port_name);
        return true;
    }else{
        RCLCPP_ERROR(this->get_logger(), "Failed to open port: %s. (%d, %s)",
                port_name, err, strerror(err));
        return false;
    }
}

void SerialIO::TimerCallback()
{    
    int rx_data;
    msg_t sensor_data;

    serial_.WriteInt(motor_angle_);    
    serial_.ReadInt(rx_data);
    
    sensor_data.data = rx_data;
    pub_->publish(sensor_data);

    RCLCPP_INFO(this->get_logger(), "Motor: %d, Sensor: %d", motor_angle_, rx_data);    
}

void SerialIO::UpdateMotorAngle(const msg_t::SharedPtr msg)
{
    motor_angle_ = msg->data;
}


int main(int argc, char* argv[])
{    
    init(argc, argv); // Note this must be placed at top of the main!

    auto node = make_shared<SerialIO>();

    // Note argv[0] is path of node's executable.
    // arg we given starts from argv[1].
    if( node->OpenPort(argv[1]) ){
        spin(node);
    }
    
    shutdown();    
    return 0;
}