#include "rclcpp/rclcpp.hpp"

class SimpleNode : public rclcpp::Node
{
public:
  SimpleNode() : Node("simple_node")
  {
    RCLCPP_INFO(this->get_logger(), "Simple Node has been started.");
  }

  int add(int a, int b)
  {
    return a + b;
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
