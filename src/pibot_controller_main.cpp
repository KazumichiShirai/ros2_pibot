#include <rclcpp/rclcpp.hpp>
#include "pibot_controller.hpp"

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PibotController>());
  rclcpp::shutdown();
  
  return 0;
}