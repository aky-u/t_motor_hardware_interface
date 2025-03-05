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

#include "t_motor_hardware_interface/t_motor/can_interface.hpp"
#include "t_motor_hardware_interface/t_motor/can_packet.hpp"
#include "t_motor_hardware_interface/t_motor/t_motor_servo.hpp"

namespace t_motor_hardware_interface {

TMotorServo::TMotorServo(uint32_t motor_id, const std::string &interface)
    : TMotorBase(motor_id, interface) {};

void TMotorServo::setDuty(float duty) const {
  if (duty > 1.0f)
    duty = 1.0f;
  if (duty < -1.0f)
    duty = -1.0f;

  // scaling
  int32_t duty_scaled = static_cast<int32_t>(duty * 100000.0f);

  // Create CAN packet
  uint8_t data[4];
  std::memcpy(data, &duty_scaled, sizeof(duty_scaled));

  uint32_t can_id = id_ | (static_cast<uint32_t>(CAN_PACKET_ID::SET_DUTY) << 8);

  can_interface_.sendCANMessage(can_id, data, sizeof(data));
}

void TMotorServo::setCurrent(float current) const {}

void TMotorServo::setCurrentBrake(float current, float brake) const {}

void TMotorServo::setRPM(float rpm) const {}

void TMotorServo::setPosition(float pos) const {}

void TMotorServo::setOriginHere() const {}

void TMotorServo::setPositionSpeed(float pos, float spd) const {}

} // namespace t_motor_hardware_interface