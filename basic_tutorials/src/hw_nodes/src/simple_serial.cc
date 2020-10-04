#include "serial_io/simple_serial.h"


errno_t SimpleSerial::Begin(const char* _port, const speed_t& _baud_rate)
{
    serial_port_ = open(_port, O_RDWR); // Open port
    if (serial_port_ < 0) { return errno; } // Validate port    
    
    if(tcgetattr(serial_port_, &tty_) != 0) { return errno; } // Read existing settings

    tty_.c_cflag &= ~PARENB;          // NO parity bit
    tty_.c_cflag |= CSTOPB;           // One stop bit
    tty_.c_cflag |= CS8;              // 8 bits per byte
    tty_.c_cflag &= ~CRTSCTS;         // Disable RTS/CTS hardware flow control 
    tty_.c_cflag |= CREAD | CLOCAL;   // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty_.c_lflag &= ~ICANON;          // Disable canonical mode
    tty_.c_lflag &= ~ISIG;            // Disable interpretation of INTR, QUIT and SUSP    
    tty_.c_lflag &= ~ECHO;            // Disable echo
    tty_.c_lflag &= ~ECHOE;           // Disable erasure
    tty_.c_lflag &= ~ECHONL;          // Disable new-line echo
    tty_.c_lflag &= ~ISIG;            // Disable interpretation of INTR, QUIT and SUSP    
    tty_.c_oflag &= ~OPOST;           // Prevent special interpretation of output bytes (e.g. newline chars)
    tty_.c_oflag &= ~ONLCR;           // Prevent conversion of newline to carriage return/line feed
    tty_.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty_.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    cfsetispeed(&tty_, _baud_rate);  // Set speed

    tcsetattr(serial_port_, TCSANOW, &tty_); // Apply settings

    tcflush(serial_port_,TCIOFLUSH); // Flush buffer
    return errno;
}

errno_t SimpleSerial::ReadInt(int& data){
    char buff[buffer_size_] = {0};
    read(serial_port_, buff, buffer_size_); // Serial Read
    std::stringstream rx_str(buff);
    rx_str >> data;
    return errno;
}

errno_t SimpleSerial::WriteInt(const int& data){    
    std::stringstream tx_str;
    tx_str << data;
    std::string tmp = tx_str.str() + "\n"; // Note write string end with \n
    write(serial_port_, tmp.c_str(), tmp.size()); // Serial Write
    return errno;
}

errno_t SimpleSerial::End()
{
    tcflush(serial_port_,TCIOFLUSH);  // Flush buffer
    close(serial_port_); // Close port
    return errno;
}