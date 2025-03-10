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

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <unistd.h>
#include <vector>

#include "t_motor_hardware_interface/servo_serial/serial_comm.hpp"

namespace t_motor_hardware_interface {

SerialComm::SerialComm(const std::string &port, unsigned int baudrate) : fd_(-1) {
  fd_ = open(port.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
  // Open non-blocking serial port
  // fd_ = open(port.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
  // fd_ = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd_ < 0) {
    std::cerr << "Error: Could not open serial port " << port << std::endl;
  }

  // Configure the port settings using termios
  struct termios tty;
  memset(&tty, 0, sizeof(tty));

  if (tcgetattr(fd_, &tty) != 0) {
    std::cerr << "Error: Unable to get terminal attributes!" << std::endl;
    close(fd_);
  }

  // Set baud rate to 961200 (set with cfsetispeed and cfsetospeed)
  // Since 961200 isn't in termios constants, we use cfsetspeed directly:
  int custom_baud_rate = baudrate;
  cfsetspeed(&tty, custom_baud_rate);

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

std::vector<uint8_t> SerialComm::readData() const {
  std::vector<uint8_t> data;
  uint8_t byte;

  // check if there is data to read
  if (fd_ < 0) {
    std::cerr << "Error: Could not read data from serial port" << std::endl;
    return data;
  }

  // Read the header byte
  auto header = read(fd_, &byte, 1); // 0x02

  // Read until we have at least one byte
  ssize_t bytes_read = 0;
  int count = 0;
  while ((bytes_read = read(fd_, &byte, 1)) > 0) {
    data.push_back(byte); // Add the byte to the data vector

    if (byte == 0x03) {
      break; // Stop reading if we reach the end byte
    }
  }

  // Handle errors or empty read
  if (bytes_read < 0) {
    std::cerr << "Error: Failed to read data from serial port" << std::endl;
  }

  return data;
}

void SerialComm::bufferAppendInt16(std::vector<uint8_t> &data, int16_t value, int index) const {
  // Append a 16-bit integer to the data buffer
  data[index] = (value >> 8) & 0xFF;
  data[index + 1] = value & 0xFF;
}

void SerialComm::bufferAppendInt32(std::vector<uint8_t> &data, int32_t value, int index) const {
  // Append a 32-bit integer to the data buffer
  data[index] = (value >> 24) & 0xFF;
  data[index + 1] = (value >> 16) & 0xFF;
  data[index + 2] = (value >> 8) & 0xFF;
  data[index + 3] = value & 0xFF;
}

int SerialComm::bufferGetInt16(const std::vector<uint8_t> &buffer, int index) const {
  // Convert two bytes to a 16-bit integer
  int16_t value = (buffer[index] << 8) | buffer[index + 1];
  return value;
}

int SerialComm::bufferGetInt32(const std::vector<uint8_t> &buffer, int index) const {
  // Convert four bytes to a 32-bit integer
  int32_t value = (buffer[index] << 24) | (buffer[index + 1] << 16) | (buffer[index + 2] << 8) |
                  buffer[index + 3];
  return value;
}

} // namespace t_motor_hardware_interface