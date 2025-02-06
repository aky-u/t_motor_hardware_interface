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

## AK Series

### AK80-8

[Here](https://www.cubemars.com/goods-1151-AK80-8.html) you can find a link for the motor.
