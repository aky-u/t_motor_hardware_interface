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

#include <fcntl.h>
#include <iostream>
#include <stdexcept>
#include <unistd.h>

#include "t_motor_hardware_interface/servo_serial/serial_comm.hpp"

namespace t_motor_hardware_interface {

SerialComm::SerialComm(const std::string &port, unsigned int baudrate) : fd_(-1) {
  // Open the serial port blocking
  fd_ = open(port.c_str(), O_RDWR | O_NOCTTY | O_SYNC);

  if (fd_ == -1) {
    throw std::runtime_error("Failed to open serial port");
  }

  // Set the baudrate
  struct termios tty;
  if (tcgetattr(fd_, &tty) != 0) {
    throw std::runtime_error("Failed to get serial port attributes");
  }

  cfsetospeed(&tty, baudrate);
  cfsetispeed(&tty, baudrate);

  if (tcsetattr(fd_, TCSANOW, &tty) != 0) {
    throw std::runtime_error("Failed to set serial port attributes");
  }

  // Set the serial port to 8N1
  tty.c_cflag &= ~PARENB;
  tty.c_cflag &= ~CSTOPB;
  tty.c_cflag &= ~CSIZE;
  tty.c_cflag |= CS8;

  if (tcsetattr(fd_, TCSANOW, &tty) != 0) {
    throw std::runtime_error("Failed to set serial port attributes");
  }
}

bool SerialComm::writeData(const std::vector<uint8_t> &data) const {
  ssize_t bytes_written = write(fd_, data.data(), data.size());
  if (bytes_written == -1) {
    std::cerr << "Failed to write data to serial port" << std::endl;
    return false;
  }

  return true;
}
} // namespace t_motor_hardware_interface