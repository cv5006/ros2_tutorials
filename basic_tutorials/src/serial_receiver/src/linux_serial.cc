#include "linux_serial.h"


/* TODO: Convert to C++ style if possible! */

void LinuxSerial::Begin(const char* _port, speed_t _baud_rate)
{
    serial_port_ = open(_port, O_RDWR);

    // Check for error
    if (serial_port_ < 0) { PrintError(); }
    
    // Create new termios struc, we call it 'tty' for convention
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port_, &tty) != 0) { PrintError(); }

    tty.c_cflag &= ~PARENB;          // NO parity bit
    tty.c_cflag &= ~CSTOPB;          // No stop bit
    tty.c_cflag |= CS8;              // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS;         // Disable RTS/CTS hardware flow control 
    tty.c_cflag |= CREAD | CLOCAL;   // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;          // Disable canonical mode
    tty.c_lflag &= ~ISIG;            // Disable interpretation of INTR, QUIT and SUSP
    
    // for input mode
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);                          // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    cfsetispeed(&tty, _baud_rate);

    if (tcsetattr(serial_port_, TCSANOW, &tty) != 0) { PrintError(); }
}

void LinuxSerial::Read(char* _rx_data)
{    
    read(serial_port_, _rx_data, sizeof(*_rx_data));
}

void LinuxSerial::Close()
{
    close(serial_port_);
}

void LinuxSerial::PrintError()
{
    //RCLCPP_ERROR(this->get_logger(), "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    //std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
}