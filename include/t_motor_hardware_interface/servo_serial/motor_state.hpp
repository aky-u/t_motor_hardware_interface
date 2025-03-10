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

#ifndef T_MOTOR_HARDWARE_INTERFACE__SERVO_SERIAL__MOTOR_STATE_HPP_
#define T_MOTOR_HARDWARE_INTERFACE__SERVO_SERIAL__MOTOR_STATE_HPP_

namespace t_motor_hardware_interface {

class MotorState {
public:
  MotorState();
  ~MotorState() = default;

  void printMotorState() const;

  // Getters
  float getMosTemperature() const { return mos_temperature_; }
  float getMotorTemperature() const { return motor_temperature_; }
  float getOutputCurrent() const { return output_current_; }
  float getInputCurrent() const { return input_current_; }
  float getIdCurrent() const { return id_current_; }
  float getIqCurrent() const { return iq_current_; }
  float getThrottleValue() const { return throttle_value_; }
  float getMotorSpeed() const { return motor_speed_; }
  float getInputVoltage() const { return input_voltage_; }
  float getMotorOuterLoopPosition() const { return motor_outer_loop_position_; }
  int getMotorId() const { return motor_id_; }
  float getVdVoltage() const { return vd_voltage_; }
  float getVqVoltage() const { return vq_voltage_; }

  // Setters
  void setMosTemperature(float mos_temperature) { mos_temperature_ = mos_temperature; }
  void setMotorTemperature(float motor_temperature) { motor_temperature_ = motor_temperature; }
  void setOutputCurrent(float output_current) { output_current_ = output_current; }
  void setInputCurrent(float input_current) { input_current_ = input_current; }
  void setIdCurrent(float id_current) { id_current_ = id_current; }
  void setIqCurrent(float iq_current) { iq_current_ = iq_current; }
  void setThrottleValue(float throttle_value) { throttle_value_ = throttle_value; }
  void setMotorSpeed(float motor_speed) { motor_speed_ = motor_speed; }
  void setInputVoltage(float input_voltage) { input_voltage_ = input_voltage; }
  void setMotorOuterLoopPosition(float motor_outer_loop_position) {
    motor_outer_loop_position_ = motor_outer_loop_position;
  }
  void setMotorId(int motor_id) { motor_id_ = motor_id; }
  void setVdVoltage(float vd_voltage) { vd_voltage_ = vd_voltage; }
  void setVqVoltage(float vq_voltage) { vq_voltage_ = vq_voltage; }

private:
  float mos_temperature_;
  float motor_temperature_;
  float output_current_;
  float input_current_;
  float id_current_;
  float iq_current_;
  float throttle_value_;
  float motor_speed_;
  float input_voltage_;
  float motor_outer_loop_position_;
  int motor_id_;
  float vd_voltage_;
  float vq_voltage_;
}; // class MotorState
} // namespace t_motor_hardware_interface

#endif // T_MOTOR_HARDWARE_INTERFACE__SERVO_SERIAL__MOTOR_STATE_HPP_