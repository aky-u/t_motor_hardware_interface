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

#ifndef T_MOTOR_HARDWARE_INTERFACE__VISIBILITY_CONTROL_H_
#define T_MOTOR_HARDWARE_INTERFACE__VISIBILITY_CONTROL_H_

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define T_MOTOR_HARDWARE_INTERFACE_EXPORT __attribute__((dllexport))
#define T_MOTOR_HARDWARE_INTERFACE_IMPORT __attribute__((dllimport))
#else
#define T_MOTOR_HARDWARE_INTERFACE_EXPORT __declspec(dllexport)
#define T_MOTOR_HARDWARE_INTERFACE_IMPORT __declspec(dllimport)
#endif
#ifdef T_MOTOR_HARDWARE_INTERFACE_BUILDING_DLL
#define T_MOTOR_HARDWARE_INTERFACE_PUBLIC T_MOTOR_HARDWARE_INTERFACE_EXPORT
#else
#define T_MOTOR_HARDWARE_INTERFACE_PUBLIC T_MOTOR_HARDWARE_INTERFACE_IMPORT
#endif
#define T_MOTOR_HARDWARE_INTERFACE_PUBLIC_TYPE T_MOTOR_HARDWARE_INTERFACE_PUBLIC
#define T_MOTOR_HARDWARE_INTERFACE_LOCAL
#else
#define T_MOTOR_HARDWARE_INTERFACE_EXPORT __attribute__((visibility("default")))
#define T_MOTOR_HARDWARE_INTERFACE_IMPORT
#if __GNUC__ >= 4
#define T_MOTOR_HARDWARE_INTERFACE_PUBLIC __attribute__((visibility("default")))
#define T_MOTOR_HARDWARE_INTERFACE_LOCAL __attribute__((visibility("hidden")))
#else
#define T_MOTOR_HARDWARE_INTERFACE_PUBLIC
#define T_MOTOR_HARDWARE_INTERFACE_LOCAL
#endif
#define T_MOTOR_HARDWARE_INTERFACE_PUBLIC_TYPE
#endif

#endif // T_MOTOR_HARDWARE_INTERFACE__VISIBILITY_CONTROL_H_
