#include "Templates.hpp"
#include "gtest/gtest.h"

TEST(StackTest, FirstTest)
{
  Stack<int> intStack(4);
  Stack<double> doubleStack(3.14);
  Stack<float> floatStack(3.1);
  Stack<std::string> stringStack("March Madness");
  Stack<std::string> stringStack2("March Madness");
  EXPECT_EQ(intStack.pop(), 4);
  EXPECT_EQ(stringStack.pop(), "March Madness");
  EXPECT_EQ(DoWork<int>::doWork(4), 4);
  std::string a("test");
  std::string b("test!");
  EXPECT_EQ(DoWork<std::string>::doWork(a), b);

  //int a = 5;
  //int b = 6;

  //swap(a, b);
  //std::swap(a, b);

}
