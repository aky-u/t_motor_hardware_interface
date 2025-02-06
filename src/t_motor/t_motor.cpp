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

#include "t_motor_hardware_interface/t_motor/t_motor.hpp"

namespace t_motor_hardware_interface {

TMotor::TMotor() = default;

TMotor::~TMotor() = default;

void TMotor::comm_can_transmit_eid(uint32_t controller_id, const uint8_t *data, uint8_t len) const {
}

void TMotor::buffer_append_int32(uint8_t *buffer, int32_t number, int32_t *index) const {}

void TMotor::buffer_append_uint16(uint8_t *buffer, uint16_t number, int32_t *index) const {}

void TMotor::comm_can_set_duty(uint8_t controller_id, float duty_cycle) const {}

void TMotor::comm_can_set_current(uint8_t controller_id, float current) const {}

void TMotor::comm_can_set_current_brake(uint8_t controller_id, float current, float brake) const {}

void TMotor::comm_can_set_rpm(uint8_t controller_id, float rpm) const {}

} // namespace t_motor_hardware_interface