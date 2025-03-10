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

#ifndef T_MOTOR_HARDWARE_INTERFACE__SERVO_SERIAL__PACKET_HPP_
#define T_MOTOR_HARDWARE_INTERFACE__SERVO_SERIAL__PACKET_HPP_

#include <cstdint>
#include <vector>

namespace t_motor_hardware_interface {

const std::vector<uint8_t> kCommandGetMotorParameters = {0x02, 0x01, 0x04, 0x40, 0x84, 0x03};

enum class COMM_PACKET_ID {
  COMM_FW_VERSION = 0,
  COMM_JUMP_TO_BOOTLOADER,
  COMM_ERASE_NEW_APP,
  COMM_WRITE_NEW_APP_DATA,
  COMM_GET_VALUES,             // Get motor operating parameters
  COMM_SET_DUTY,               // Motor operates in duty cycle mode
  COMM_SET_CURRENT,            // Motor operates in current loop mode
  COMM_SET_CURRENT_BRAKE,      // Motor operates in current brake mode
  COMM_SET_RPM,                // Motor operates in speed loop mode
  COMM_SET_POS,                // Motor operates in position loop mode
  COMM_SET_HANDBRAKE,          // Motor operates in handbrake current loop mode
  COMM_SET_DETECT,             // Motor real-time feedback current position command
  COMM_ROTOR_POSITION = 22,    // Motor feedback current position
  COMM_GET_VALUES_SETUP = 50,  // Motor single or multiple parameter acquisition command
  COMM_SET_POS_SPD = 91,       // Motor operates in position-speed loop mode
  COMM_SET_POS_MULTI = 92,     // Set motor motion to single-turn mode
  COMM_SET_POS_SINGLE = 93,    // Set motor motion to multi-turn mode, range ±100 turns
  COMM_SET_POS_UNLIMITED = 94, // Reserved
  COMM_SET_POS_ORIGIN = 95,    // Set motor motion to origin
};

} // namespace t_motor_hardware_interface

#endif // T_MOTOR_HARDWARE_INTERFACE__SERVO_SERIAL__PACKET_HPP_