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

#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()



class SimpleSerial
{
public:
    SimpleSerial() {};
    ~SimpleSerial() {};

    void Begin(std::string _port, speed_t _baud_rate);
    void Read(std::string& _rx);
    void Write(const std::string& _tx_data);
    void Close();
    void Flush();

private:
    int serial_port_;

    void PrintError();
};

#endif


