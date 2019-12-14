#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>

class PibotController : public rclcpp::Node
{
private:
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
public:
    PibotController();
};