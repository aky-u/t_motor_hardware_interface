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

#include <boost/asio.hpp>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

#include "t_motor_hardware_interface/t_motor_driver/comm/serial_comm.hpp"
#include "t_motor_hardware_interface/t_motor_driver/protocol/serial_protocol.hpp"

namespace t_motor_hardware_interface {

SerialComm::SerialComm(const std::string &port_name)
    : IMotorComm(), port_name_(port_name), serial_port_(io_service_) {}

SerialComm::~SerialComm() {
  if (serial_port_.is_open()) {
    serial_port_.close();
  }
}

bool SerialComm::initialize() {
  try {
    serial_port_.open(port_name_);
    serial_port_.set_option(boost::asio::serial_port_base::baud_rate(115200)); // Change baud rate
    serial_port_.set_option(boost::asio::serial_port_base::character_size(8)); // Keep 8 data bits
    serial_port_.set_option(boost::asio::serial_port_base::stop_bits(
        boost::asio::serial_port_base::stop_bits::one)); // Try one stop bit
    serial_port_.set_option(boost::asio::serial_port_base::parity(
        boost::asio::serial_port_base::parity::none)); // No parity
    serial_port_.set_option(boost::asio::serial_port_base::flow_control(
        boost::asio::serial_port_base::flow_control::none)); // No flow control
  } catch (const boost::system::system_error &e) {
    std::cerr << "Error opening serial port: " << e.what() << std::endl;
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

bool SerialComm::readMessage(uint8_t *data, uint8_t &len) const {
  // Read data from serial port
  // boost::asio::streambuf buf;
  // boost::asio::read_until(serial_port_, buf, '\n');
  // std::istream is(&buf);
  // std::string line;
  // std::getline(is, line);
  // std::cout << "Received: " << line << std::endl;

  return true;
}

} // namespace t_motor_hardware_interface