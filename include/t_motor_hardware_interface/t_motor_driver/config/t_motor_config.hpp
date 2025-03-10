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

#ifndef T_MOTOR_HARDWARE_INTERFACE__T_MOTOR_DRIVER__CONFIG_HPP_
#define T_MOTOR_HARDWARE_INTERFACE__T_MOTOR_DRIVER__CONFIG_HPP_

namespace t_motor_hardware_interface {

/**
 * @struct TMotorConfig
 * @brief Configuration parameters for the motor
 */
struct TMotorConfig {
  int min_position;  // Minimum position limit
  int max_position;  // Maximum position limit
  int min_velocity;  // Minimum velocity limit
  int max_velocity;  // Maximum velocity limit
  int min_current;   // Minimum current limit
  int max_current;   // Maximum current limit
  int min_torque;    // Minimum torque limit
  int max_torque;    // Maximum torque limit
  double kt;         //
  double gear_ratio; // Gear ratio
};

// Default configuration parameters
// TODO: Set randomly for now
const TMotorConfig AK_80_8 = {
    .min_position = -32000,
    .max_position = 32000,
    .min_velocity = -32000,
    .max_velocity = 32000,
    .min_current = -32000,
    .max_current = 32000,
    .min_torque = -32000,
    .max_torque = 32000,
    .kt = 0.0,
    .gear_ratio = 0.0,
};

} // namespace t_motor_hardware_interface
#endif // T_MOTOR_HARDWARE_INTERFACE__T_MOTOR_DRIVER__CONFIG_HPP_