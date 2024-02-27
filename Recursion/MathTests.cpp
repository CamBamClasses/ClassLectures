#include "Math.hpp"
#include "gtest/gtest.h"

TEST(MathTests, Recursion)
{
  //std::cout.sync_with_stdio(false);

  std::vector<int> myCache;

  EXPECT_EQ(math::sigmaNum(5), 15);
  EXPECT_EQ(math::fibonacci(0, myCache), 0);
  EXPECT_EQ(math::fibonacci(1, myCache), 1);
  EXPECT_EQ(math::fibonacci(2, myCache), 1);
  EXPECT_EQ(math::fibonacci(3, myCache), 2);
  EXPECT_EQ(math::fibonacci(30, myCache), 832040);
}
