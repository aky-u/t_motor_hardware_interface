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

#include "t_motor_hardware_interface/t_motor/t_motor_base.hpp"

namespace t_motor_hardware_interface {

TMotorBase::TMotorBase(uint32_t motor_id, const std::string &interface)
    : id_(motor_id), can_interface_(interface) {}

ERROR_CODE TMotorBase::readState() {
  struct can_frame frame;
  if (can_interface_.readCANMessage(frame)) {
    //
  }
}

std::string TMotorBase::getErrorString() const {
  switch (error_) {
  case ERROR_CODE::NONE:
    return "No error";
  case ERROR_CODE::OVER_VOLTAGE:
    return "Over voltage";
  case ERROR_CODE::UNDER_VOLTAGE:
    return "Under voltage";
  case ERROR_CODE::DRV:
    return "Driver fault";
  case ERROR_CODE::ABS_OVER_CURRENT:
    return "Motor over current";
  case ERROR_CODE::OVER_TEMP_FET:
    return "MOS over temperature";
  case ERROR_CODE::OVER_TEMP_MOTOR:
    return "Motor over temperature";
  case ERROR_CODE::GATE_DRIVER_OVER_VOLTAGE:
    return "Driver over voltage";
  case ERROR_CODE::GATE_DRIVER_UNDER_VOLTAGE:
    return "Driver under voltage";
  case ERROR_CODE::MCU_UNDER_VOLTAGE:
    return "MCU under voltage";
  case ERROR_CODE::BOOTING_FROM_WATCHDOG_RESET:
    return "Booting from watchdog reset";
  case ERROR_CODE::ENCODER_SPI:
    return "SPI encoder fault";
  case ERROR_CODE::ENCODER_SINCOS_BELOW_MIN_AMPLITUDE:
    return "Encoder below minimum amplitude";
  case ERROR_CODE::ENCODER_SINCOS_ABOVE_MAX_AMPLITUDE:
    return "Encoder above maximum amplitude";
  case ERROR_CODE::FLASH_CORRUPTION:
    return "Flash fault";
  case ERROR_CODE::HIGH_OFFSET_CURRENT_SENSOR_1:
    return "Current sampling channel 1 fault";
  case ERROR_CODE::HIGH_OFFSET_CURRENT_SENSOR_2:
    return "Current sampling channel 2 fault";
  case ERROR_CODE::HIGH_OFFSET_CURRENT_SENSOR_3:
    return "Current sampling channel 3 fault";
  case ERROR_CODE::UNBALANCED_CURRENTS:
    return "Unbalanced currents";
  default:
    return "Unknown error";
  } // switch
} // getErrorString
} // namespace t_motor_hardware_interface