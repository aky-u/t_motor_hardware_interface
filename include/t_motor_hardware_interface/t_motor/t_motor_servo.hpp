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

#ifndef T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__T_MOTOR_SERVO_HPP_
#define T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__T_MOTOR_SERVO_HPP_

#include <cstdint>

#include "t_motor_hardware_interface/t_motor/t_motor_base.hpp"

namespace t_motor_hardware_interface {

/**
 * @class TMotorServo
 * @brief Class for servo motor control
 */
class TMotorServo : public TMotorBase {
public:
  TMotorServo();
  ~TMotorServo() = default;

  void comm_can_set_pos(uint8_t controller_id, float pos) const;
  void comm_can_set_origin_here(uint8_t controller_id) const;
  void comm_can_set_pos_spd(uint8_t controller_id, float pos, float spd) const;
};

} // namespace t_motor_hardware_interface

#endif // T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__T_MOTOR_SERVO_HPP_