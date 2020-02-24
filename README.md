# ROS2_PiBOT
<img src="https://user-images.githubusercontent.com/1625932/72203578-ba238580-34b0-11ea-9230-da99632cd875.jpg" width="600px">

# Hardware
 - Raspberry Pi 3 B+
 - [タミヤ ショベルドーザー工作基本セット](https://www.amazon.co.jp/%E3%82%BF%E3%83%9F%E3%83%A4-%E6%A5%BD%E3%81%97%E3%81%84%E5%B7%A5%E4%BD%9C%E3%82%B7%E3%83%AA%E3%83%BC%E3%82%BA-No-107-%E3%82%B7%E3%83%A7%E3%83%99%E3%83%AB%E3%83%89%E3%83%BC%E3%82%B6%E3%83%BC%E5%B7%A5%E4%BD%9C%E5%9F%BA%E6%9C%AC%E3%82%BB%E3%83%83%E3%83%88-70107/dp/B002DR3H5I/ref=pd_aw_sbs_21_5/356-6988335-3432811?_encoding=UTF8&pd_rd_i=B002DR3H5I&pd_rd_r=47ed4ac3-e9e9-4253-87ec-194fb1966823&pd_rd_w=8iAcA&pd_rd_wg=sCtHp&pf_rd_p=1893a417-ba87-4709-ab4f-0dece788c310&pf_rd_r=8J7W5P57K8F1MMVJAQH6&psc=1&refRID=8J7W5P57K8F1MMVJAQH6)
 - モバイルバッテリー
 - [ＴＢ６６１２使用　Ｄｕａｌ　ＤＣモータードライブキット](http://akizukidenshi.com/catalog/g/gK-11219/)

# 動作環境
Ubuntu-18.04.3 64bit (Rapsberry Pi 3 B+にインストールする)

Raspbianではないので、注意

# 事前インストール
## ROS2

## pigpio
http://abyz.me.uk/rpi/pigpio/download.html 通りにインストール

```
wget https://github.com/joan2937/pigpio/archive/v74.zip
unzip v74.zip
cd pigpio-74
make
sudo make install
```
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
