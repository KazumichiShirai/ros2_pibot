# files

 ##  motor_control.cpp
 ##  pibot_controller.cpp

# ROS API
## ~contoller/joy  [(sensor_msgs/Joy)](http://docs.ros.org/api/sensor_msgs/html/msg/Joy.html)

# memo
## motor_control.cpp
### 概要
 - joy[X]とjoy[Y]をもらい、その値に応じて２つのモーターを制御する
### 関数
 - drive(X, Y): XとYのRageは[-1.0:1.0]
 - https://www.openrtm.org/openrtm/sites/default/files/6135/161110-06.pdf


## pigpio
 - http://abyz.me.uk/rpi/pigpio/download.html 通りにインストール

## gamepad
- logicool gamepad f310
- sudo apt install ros2-dashing-joy
- sudo apt install ros-dashing-joy-teleop
