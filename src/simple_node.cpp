#include "arcanain_unittest_template/simple_node.hpp"

SimpleNode::SimpleNode() : Node("simple_node")
{
  RCLCPP_INFO(this->get_logger(), "Simple Node has been started.");
}

int SimpleNode::add(int a, int b)
{
  return a + b;
}
