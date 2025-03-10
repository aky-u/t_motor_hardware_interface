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

#include <iostream>

#include "t_motor_hardware_interface/servo_serial/packet.hpp"
#include "t_motor_hardware_interface/servo_serial/servo_serial.hpp"

namespace t_motor_hardware_interface {

ServoSerial::ServoSerial(const std::string &port, unsigned int baudrate)
    : serial_comm_(port, baudrate) {}

bool ServoSerial::readMotorParameters() {
  bool write_success = serial_comm_.writeData(kCommandGetMotorParameters);
  if (!write_success) {
    std::cerr << "Error: Could not write data to serial port" << std::endl;
    return false;
  }

  // read data
  std::vector<uint8_t> data = serial_comm_.readData();

  // print data
  std::cout << "Received data: ";
  auto motor_state = parseMotorParameters(data);
  motor_state.printMotorState();
}

MotorState ServoSerial::parseMotorParameters(const std::vector<uint8_t> &data) const {
  MotorState motor_state;
  // Parse the data and fill in the motor state object

  float mos_temperature = (data[4] << 8 | data[5]) / 100.0;
  motor_state.setMosTemperature(mos_temperature);

  return motor_state;
}

} // namespace t_motor_hardware_interface