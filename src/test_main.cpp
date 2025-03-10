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

// This is a temporary file to test the motor hardware interface
// TODO: Move this to a separate package

#include <iostream>
#include <unistd.h>

#include "t_motor_hardware_interface/servo_serial/serial_comm.hpp"
#include "t_motor_hardware_interface/t_motor_hardware_interface.hpp"

using namespace t_motor_hardware_interface;

int main() {
  std::cout << "Testing motor hardware interface..." << std::endl;
  SerialComm serial_comm("/dev/ttyUSB0", 961200);

  std::vector<uint8_t> data = {0x02, 0x01, 0x04, 0x40, 0x84, 0x03};
  serial_comm.writeData(data);
}
