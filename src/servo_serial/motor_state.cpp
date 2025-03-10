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

#include "t_motor_hardware_interface/servo_serial/motor_state.hpp"

namespace t_motor_hardware_interface {

MotorState::MotorState()
    : mos_temperature_(0.0),           //
      motor_temperature_(0.0),         //
      output_current_(0.0),            //
      input_current_(0.0),             //
      id_current_(0.0),                //
      iq_current_(0.0),                //
      throttle_value_(0.0),            //
      motor_speed_(0.0),               //
      input_voltage_(0.0),             //
      motor_outer_loop_position_(0.0), //
      motor_id_(0),                    //
      vd_voltage_(0.0),                //
      vq_voltage_(0.0) {}

void MotorState::printMotorState() const {
  // Print the motor state
  std::cout << "Motor State:" << std::endl;
  std::cout << "  MOS Temperature: " << mos_temperature_ << std::endl;
  std::cout << "  Motor Temperature: " << motor_temperature_ << std::endl;
  std::cout << "  Output Current: " << output_current_ << std::endl;
  std::cout << "  Input Current: " << input_current_ << std::endl;
  std::cout << "  Id Current: " << id_current_ << std::endl;
  std::cout << "  Iq Current: " << iq_current_ << std::endl;
  std::cout << "  Throttle Value: " << throttle_value_ << std::endl;
  std::cout << "  Motor Speed: " << motor_speed_ << std::endl;
  std::cout << "  Input Voltage: " << input_voltage_ << std::endl;
  std::cout << "  Motor Outer Loop Position: " << motor_outer_loop_position_ << std::endl;
  std::cout << "  Motor ID: " << motor_id_ << std::endl;
  std::cout << "  Vd Voltage: " << vd_voltage_ << std::endl;
  std::cout << "  Vq Voltage: " << vq_voltage_ << std::endl;
}

} // namespace t_motor_hardware_interface