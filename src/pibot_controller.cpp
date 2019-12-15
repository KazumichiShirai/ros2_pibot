#include  <rclcpp/rclcpp.hpp>
#include  <sensor_msgs/msg/joy.hpp>
#include  "pibot_controller.hpp"
#include "motor_control.hpp"

MotorControl  motor_control = MotorControl(0);

PibotController::PibotController()
: Node("pibot_controller"){
    subscription_=this->create_subscription<sensor_msgs::msg::Joy>(
        "controller/joy",
        [this](const sensor_msgs::msg::Joy::SharedPtr joy){
            motor_control.drive();
            RCLCPP_INFO(this->get_logger(), "Joy: %f", joy->axes[0]);
        }
    );
}
