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
#include <iostream>

#include <string.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()



class SimpleSerial
{
public:
    SimpleSerial() {};
    ~SimpleSerial() { End(); };

    void Begin(std::string _port, speed_t _baud_rate);
    void ReadByte(char* rx);
    void WriteByte(const char tx);
    void Write(const std::string& tx);
    void End();

private:
    int serial_port_;
    const size_t buffer_size_ = 1024;

    void PrintError();
};

#endif


