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
#include <iostream>
#include <unistd.h>

#include "t_motor_hardware_interface/t_motor/can_interface.hpp"

namespace t_motor_hardware_interface {

CANInterface::CANInterface(const std::string &interface)
    : can_interface_name_(interface), socket_fd_(-1) {}

CANInterface::~CANInterface() {
  if (socket_fd_ >= 0) {
    close(socket_fd_);
  }
}

bool CANInterface::initialize() {
  socket_fd_ = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  if (socket_fd_ < 0) {
    std::cerr << "Error opening CAN socket!" << std::endl;
    return false;
  }

  std::strncpy(ifr_.ifr_name, can_interface_name_.c_str(), IFNAMSIZ - 1);
  if (ioctl(socket_fd_, SIOCGIFINDEX, &ifr_) < 0) {
    std::cerr << "Error getting CAN interface index!" << std::endl;
    return false;
  }

  addr_.can_family = AF_CAN;
  addr_.can_ifindex = ifr_.ifr_ifindex;
  if (bind(socket_fd_, (struct sockaddr *)&addr_, sizeof(addr_)) < 0) {
    std::cerr << "Error binding CAN socket!" << std::endl;
    return false;
  }

  return true;
}

bool CANInterface::sendCANMessage(uint32_t can_id, const uint8_t *data, uint8_t len) const {
  struct can_frame frame;
  std::memset(&frame, 0, sizeof(frame));
  frame.can_id = can_id;
  frame.can_dlc = len;
  std::memcpy(frame.data, data, len);

  if (write(socket_fd_, &frame, sizeof(frame)) != sizeof(frame)) {
    std::cerr << "Error sending CAN message!" << std::endl;
    return false;
  }

  return true;
}

bool CANInterface::readCANMessage(struct can_frame &frame) const {
  if (read(socket_fd_, &frame, sizeof(frame)) < 0) {
    std::cerr << "Error reading CAN message!" << std::endl;
    return false;
  }

  return true;
}

} // namespace t_motor_hardware_interface
