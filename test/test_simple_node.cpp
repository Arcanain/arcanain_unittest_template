#include <gtest/gtest.h>
#include "arcanain_unittest_template/simple_node.hpp"

TEST(SimpleNodeTest, TestAdd)
{
  SimpleNode node;
  EXPECT_EQ(node.add(1, 1), 2);
  EXPECT_EQ(node.add(-1, -1), -2);
  EXPECT_EQ(node.add(-1, 1), 0);
  EXPECT_EQ(node.add(100, 200), 300);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
