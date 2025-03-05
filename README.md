# t_motor_hardware_interface

This is a repository which provides ros2 control hardware interface for t-motor.

## Installation

Clone this repository and build.

```bash
mkdir -p t_motor_ws/src
cd t_motor_ws/src
git clone git@github.com:aky-u/t_motor_hardware_interface.git
```

```bash
cd ../
rosdep install -i -y --from-path src/
```

```bash
cd ../
colcon build --symlink-install
```

```bash
source install/setup.bash
```

## How to test

### Set up virtual CAN

```bash
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set vcan0 txqueuelen 1000
sudo ip link set up vcan0
```

### Enable CAN communication

```bash
sudo ip link set can0 up type can bitrate 1000000
```

### Send can command

```bash
cansend vcan0 123#0102030405060708
```

## How to connect T-Motor

### Activate can

```bash
sudo modprobe slcan
sudo slcand -o -s8 -t hw -S 3000000 /dev/ttyUSB0 slcan0
sudo ip link set up slcan0
```

## AK Series

### AK80-8

[Here](https://www.cubemars.com/goods-1151-AK80-8.html) you can find a link for the motor.

## Related works

- <https://github.com/neurobionics/TMotorCANControl>

- <https://github.com/dfki-ric-underactuated-lab/mini-cheetah-tmotor-python-can>

- <https://github.com/SherbyRobotics/tmotor_ros>
