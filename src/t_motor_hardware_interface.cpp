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

#include "t_motor_hardware_interface/t_motor_hardware_interface.hpp"

namespace t_motor_hardware_interface {

TMotorHardware::TMotorHardware() : rclcpp::Node("t_motor_hardware_interface") {}

hardware_interface::CallbackReturn
TMotorHardware::on_init(const hardware_interface::HardwareInfo &info) {}

std::vector<hardware_interface::StateInterface> TMotorHardware::export_state_interfaces() {}

std::vector<hardware_interface::CommandInterface> TMotorHardware::export_command_interfaces() {}

hardware_interface::CallbackReturn
TMotorHardware::on_activate(const rclcpp_lifecycle::State &previous_state) {}

hardware_interface::CallbackReturn
TMotorHardware::on_deactivate(const rclcpp_lifecycle::State &new_state) {}

hardware_interface::return_type TMotorHardware::read(const rclcpp::Time &time,
                                                     const rclcpp::Duration &period) {}

hardware_interface::return_type TMotorHardware::write(const rclcpp::Time &time,
                                                      const rclcpp::Duration &period) {}

} // namespace t_motor_hardware_interface