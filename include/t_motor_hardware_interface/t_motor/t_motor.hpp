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

#ifndef T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__T_MOTOR_HPP_
#define T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__T_MOTOR_HPP_

#include <cstdint>

namespace t_motor_hardware_interface {

/**
 * @enum CAN_PACKET_ID
 * @brief CAN packet ID
 */
enum class CAN_PACKET_ID {
  CAN_PACKET_SET_DUTY = 0,      // Duty Cycle Mode
  CAN_PACKET_SET_CURRENT,       // Current Loop Mode
  CAN_PACKET_SET_CURRENT_BRAKE, // Current Brake Mode
  CAN_PACKET_SET_RPM,           // Speed Mode
  CAN_PACKET_SET_POS,           // Position Mode
  CAN_PACKET_SET_ORIGIN_HERE,   // Set Origin Mode
  CAN_PACKET_SET_POS_SPD,       // Position-Speed Loop Mode
};

class TMotor {
public:
  TMotor();
  ~TMotor() = default;

private:
  void comm_can_transmit_eid(uint32_t id, const uint8_t *data, uint8_t len) const;

  void buffer_append_int32(uint8_t *buffer, int32_t number, int32_t *index) const;

  void buffer_append_uint16(uint8_t *buffer, uint16_t number, int32_t *index) const;

  void comm_can_set_duty(uint8_t controller_id, float duty) const;

  void comm_can_set_current(uint8_t controller_id, float current) const;

  void comm_can_set_current_brake(uint8_t controller_id, float current, float brake) const;

  void comm_can_set_rpm(uint8_t controller_id, float rpm) const;
};
} // namespace t_motor_hardware_interface

#endif // T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__T_MOTOR_HPP_