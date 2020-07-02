#include "simple_serial.h"


/* TODO: Convert to C++ style if possible! */

void SimpleSerial::Begin(std::string _port, speed_t _baud_rate)
{
    serial_port_ = open(_port.c_str(), O_RDWR);

    // Check for error
    if (serial_port_ < 0) { PrintError(); }
    
    // Create new termios struc, we call it 'tty' for convention
    struct termios tty = {};
    

    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port_, &tty) != 0) { PrintError(); }

    tty.c_cflag &= ~PARENB;          // NO parity bit
    tty.c_cflag &= ~CSTOPB;          // No stop bit
    tty.c_cflag |= CS8;              // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS;         // Disable RTS/CTS hardware flow control 
    tty.c_cflag |= CREAD | CLOCAL;   // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;          // Disable canonical mode
    tty.c_lflag &= ~ISIG;            // Disable interpretation of INTR, QUIT and SUSP    
    tty.c_lflag &= ~ECHO;            // Disable echo
    tty.c_lflag &= ~ECHOE;           // Disable erasure
    tty.c_lflag &= ~ECHONL;          // Disable new-line echo
    tty.c_lflag &= ~ISIG;            // Disable interpretation of INTR, QUIT and SUSP    
    tty.c_oflag &= ~OPOST;           // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR;           // Prevent conversion of newline to carriage return/line feed
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes


    cfsetispeed(&tty, _baud_rate);

    if (tcsetattr(serial_port_, TCSANOW, &tty) != 0) { PrintError(); }
}

void SimpleSerial::Read(std::string& _rx)
{
    char buff[1] = {};
    read(serial_port_, buff, sizeof(buff));
    _rx = buff;    
}

void SimpleSerial::Write(const std::string& _tx){    
    write(serial_port_, _tx.c_str(), _tx.size());
}

void SimpleSerial::Close()
{
    close(serial_port_);
}

void SimpleSerial::Flush()
{
    tcflush(serial_port_,TCIOFLUSH);
}

void SimpleSerial::PrintError()
{
    //RCLCPP_ERROR(this->get_logger(), "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    std::cout << "Error " << errno << " from tcgetattr: " << std::endl;
}