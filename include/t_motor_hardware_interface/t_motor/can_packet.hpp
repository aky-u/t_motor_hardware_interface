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

#ifndef T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__CAN_PACKET_HPP_
#define T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__CAN_PACKET_HPP_

namespace t_motor_hardware_interface {

// Default messages for motor control
constexpr uint8_t POWER_ON_MSG[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC};
constexpr uint8_t POWER_OFF_MSG[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD};
constexpr uint8_t SET_ZERO_POSITION_MSG[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE};

/**
 * @enum CAN_PACKET_ID
 * @brief CAN packet ID for servo motor control
 */
enum class CAN_PACKET_ID {
  SET_DUTY = 0,      // Duty Cycle Mode
  SET_CURRENT,       // Current Loop Mode
  SET_CURRENT_BRAKE, // Current Brake Mode
  SET_RPM,           // Speed Mode
  SET_POS,           // Position Mode
  SET_ORIGIN_HERE,   // Set Origin Mode
  SET_POS_SPD,       // Position-Speed Loop Mode
}; // enum class CAN_PACKET_ID

/**
 * @brief Error codes
 */
enum class ERROR_CODE {
  NONE = 0,
  OVER_VOLTAGE,                       // Overvoltage
  UNDER_VOLTAGE,                      // Undervoltage
  DRV,                                // Driver fault
  ABS_OVER_CURRENT,                   // Motor overcurrent
  OVER_TEMP_FET,                      // MOS overtemperature
  OVER_TEMP_MOTOR,                    // Motor overtemperature
  GATE_DRIVER_OVER_VOLTAGE,           // Driver overvoltage
  GATE_DRIVER_UNDER_VOLTAGE,          // Driver undervoltage
  MCU_UNDER_VOLTAGE,                  // MCU undervoltage
  BOOTING_FROM_WATCHDOG_RESET,        // Undervoltage
  ENCODER_SPI,                        // SPI encoder fault
  ENCODER_SINCOS_BELOW_MIN_AMPLITUDE, // Encoder below minimumamplitude
  ENCODER_SINCOS_ABOVE_MAX_AMPLITUDE, // Encoder above maximumamplitude
  FLASH_CORRUPTION,                   // Flash fault
  HIGH_OFFSET_CURRENT_SENSOR_1,       // Current sampling channel 1 fault
  HIGH_OFFSET_CURRENT_SENSOR_2,       // Current sampling channel 2 fault
  HIGH_OFFSET_CURRENT_SENSOR_3,       // Current sampling channel 3 fault
  UNBALANCED_CURRENTS,                // Unbalanced currents
};

} // namespace t_motor_hardware_interface

#endif // T_MOTOR_HARDWARE_INTERFACE__T_MOTOR__CAN_PACKET_HPP_