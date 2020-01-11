# ROS2_PiBOT
<img src="https://user-images.githubusercontent.com/1625932/72203578-ba238580-34b0-11ea-9230-da99632cd875.jpg" width="600px">

# files

 ##  motor_control.cpp
 ##  pibot_controller.cpp

# ROS API
## ~controller/joy  [(sensor_msgs/Joy)](http://docs.ros.org/api/sensor_msgs/html/msg/Joy.html)

# memo
## motor_control.cpp
### 概要
 - joy[X]とjoy[Y]をもらい、その値に応じて２つのモーターを制御する
### 関数
 - drive(X, Y): XとYのRageは[-1.0:1.0]
 - https://www.openrtm.org/openrtm/sites/default/files/6135/161110-06.pdf


## pigpio
 - http://abyz.me.uk/rpi/pigpio/download.html 通りにインストール
 - pigpioの関数は、スーパーユーザ権限でないと実行できない
 ```
 $ sudo su
 # . install/setup.bash
```
上記のコマンドをしてから実行

## gamepad
- logicool gamepad f310
- sudo apt install ros2-dashing-joy
- sudo apt install ros-dashing-joy-teleop

## 同じネットワークでROS2
 - ROS_DOMAIN_IDで接続
 - VMWareを使っている場合は、ブリッジ接続にする
