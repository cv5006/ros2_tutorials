#include "serial_io/simple_serial.h"


void SimpleSerial::Begin(const std::string& _port, const speed_t& _baud_rate)
{
    serial_port_ = open(_port.c_str(), O_RDWR);

    // Check for error
    if (serial_port_ < 0) { PrintError(); }
    
    // Create new termios struc, we call it 'tty' for convention
    struct termios tty = {};
    

    // Read in existing settings, and handle any error
    if(tcgetattr(serial_port_, &tty) != 0) { PrintError(); }

    tty.c_cflag &= ~PARENB;          // NO parity bit
    tty.c_cflag |= CSTOPB;           // One stop bit
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

void SimpleSerial::WriteByte(const char tx){    
    write(serial_port_, &tx, 1);
}

errno_t SimpleSerial::ReadInt(int& data){
    char buff[buffer_size_] = {0};
    read(serial_port_, buff, buffer_size_);
    std::stringstream rx_str(buff);
    rx_str >> data;
    return errno;
}

errno_t SimpleSerial::WriteInt(const int& data){    
    std::stringstream tx_str;
    tx_str << data;
    std::string tmp = tx_str.str() + "\n";
    write(serial_port_, tmp.c_str(), tmp.size());    
    return errno;
}

void SimpleSerial::Write(const std::string& tx)
{
    write(serial_port_, tx.c_str() , strlen(tx.c_str()));
}

void SimpleSerial::End()
{
    tcflush(serial_port_,TCIOFLUSH);
    close(serial_port_);
}

void SimpleSerial::PrintError()
{
    //RCLCPP_ERROR(this->get_logger(), "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
}