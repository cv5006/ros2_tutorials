/*
 * simple_serial.h
 * 
 * references: 
 * Linux headers https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
 * 
 */
#ifndef SERIAL_RECEIVER_SIMPLE_SERIAL_H_
#define SERIAL_RECEIVER_SIMPLE_SERIAL_H_

#include <string>
#include <sstream>
#include <iostream>

#include <string.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

typedef int errno_t;

class SimpleSerial
{
public:
    SimpleSerial() {};
    ~SimpleSerial() { End(); };

    void Begin(const std::string& _port, const speed_t& _baud_rate);    
    errno_t ReadInt(int& data);
    void WriteByte(const char tx);
    void Write(const std::string& tx);
    errno_t WriteInt(const int& data);
    void End();

private:
    int serial_port_;
    static const size_t buffer_size_ = 32;

    void PrintError();
};

#endif


