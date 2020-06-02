/*
 * linux_serial.h
 * 
 * references: 
 * Linux headers https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
 * 
 */
#ifndef SERIAL_RECEIVER_LINUX_SERIAL_H_
#define SERIAL_RECEIVER_LINUX_SERIAL_H_

#include <string.h>

#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()



class LinuxSerial
{
public:
    LinuxSerial() {};
    ~LinuxSerial() {};

    void Begin(const char* _port, speed_t _baud_rate);
    void Read(char* _rx_data);
    void Close();

private:
    int serial_port_;

    void PrintError();
};

#endif


