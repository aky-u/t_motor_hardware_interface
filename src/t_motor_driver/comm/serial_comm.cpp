// MIT License

// Copyright (c) 2025 aky-u

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// This file is part of the t_motor_hardware_interface package. It is written based on the AK Series
// User Manual (v1.0.15.x) by CubeMars. You can find the manual at:

// https://www.cubemars.com/images/file/20240611/1718085712815162.pdf

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "t_motor_hardware_interface/t_motor_driver/comm/serial_comm.hpp"
#include "t_motor_hardware_interface/t_motor_driver/protocol/serial_protocol.hpp"

namespace t_motor_hardware_interface {

SerialComm::SerialComm(const std::string &port_name)
    : IMotorComm(), port_name_(port_name), fd_(-1) {}

SerialComm::~SerialComm() {
  if (fd_ >= 0) {
    close(fd_);
  }
}

bool SerialComm::initialize() {
  // Open the serial port
  fd_ = open(port_name_.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
  if (fd_ < 0) {
    std::cerr << "Error: Could not open serial port " << port_name_ << std::endl;
    return false;
  }

  // Configure the port settings using termios
  struct termios tty;
  memset(&tty, 0, sizeof(tty));

  if (tcgetattr(fd_, &tty) != 0) {
    std::cerr << "Error: Unable to get terminal attributes!" << std::endl;
    close(fd_);
    return false;
  }

  // Set baud rate to 961200 (set with cfsetispeed and cfsetospeed)
  // Since 961200 isn't in termios constants, we use cfsetspeed directly:
  int custom_baud_rate = 961200;
  cfsetispeed(&tty, custom_baud_rate);
  cfsetospeed(&tty, custom_baud_rate);

  // Set 8 data bits, no parity, and 1 stop bit
  tty.c_cflag &= ~PARENB; // No parity
  tty.c_cflag &= ~CSTOPB; // 1 stop bit
  tty.c_cflag &= ~CSIZE;  // Clear data size
  tty.c_cflag |= CS8;     // 8 data bits

  // Set the number of control lines (disable RTS/CTS)
  tty.c_cflag &= ~CRTSCTS; // Disable hardware flow control

  // Set canonical mode (raw input/output)
  tty.c_lflag &= ~ICANON; // Non-canonical mode (raw)
  tty.c_lflag &= ~ECHO;   // Disable echo
  tty.c_lflag &= ~ECHOE;  // Disable erase
  tty.c_lflag &= ~ISIG;   // Disable signal generation

  // Disable software flow control
  tty.c_iflag &= ~(IXON | IXOFF | IXANY);

  // Set minimum number of bytes to read
  tty.c_cc[VMIN] = 1;
  tty.c_cc[VTIME] = 0;

  // Apply the settings
  if (tcsetattr(fd_, TCSANOW, &tty) != 0) {
    std::cerr << "Error: Unable to set terminal attributes!" << std::endl;
    close(fd_);
    return false;
  }

  return true;
}

bool SerialComm::sendMessage(const uint32_t motor_id, const uint8_t *data,
                             const uint8_t len) const {}

bool SerialComm::readState(TMotorState &state) const {
  uint8_t data[8];
  uint8_t len = 0;
  if (!readMessage(data, len)) {
    return false;
  }
  return true;
}

bool SerialComm::readMessage(uint8_t *data, uint8_t &len) const {}

} // namespace t_motor_hardware_interface