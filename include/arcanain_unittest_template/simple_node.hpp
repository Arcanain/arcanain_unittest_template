#ifndef SIMPLE_NODE_H
#define SIMPLE_NODE_H

#include "rclcpp/rclcpp.hpp"

class SimpleNode : public rclcpp::Node
{
public:
  SimpleNode();
  int add(int a, int b);
};

#endif // SIMPLE_NODE_H
