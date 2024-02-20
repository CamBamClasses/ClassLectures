#include "FunnyNumber.hpp"
#include "gtest/gtest.h"

TEST(FunnyNumberTest, Constructor)
{
  FunnyNumber num;
  EXPECT_EQ(num.getNumber(), 12);
}

TEST(FunnyNumberTest, ParamConstructor1)
{
  FunnyNumber num(12);
  EXPECT_EQ(num.getNumber(), 11);
}

TEST(FunnyNumberTest, ParamConstructor2)
{
  FunnyNumber num(0);
  EXPECT_EQ(num.getNumber(), -1);
}

TEST(FunnyNumberTest, IsEquals)
{
  FunnyNumber num1(0);
  FunnyNumber num2(0);
  EXPECT_TRUE(num1 == num2);
  EXPECT_TRUE(num1 == -1);
}


TEST(FunnyNumberTest, PlusEquals)
{
  FunnyNumber num1(12);
  FunnyNumber num2(2);
  num1 += num2;
  EXPECT_EQ(num1.getNumber(), 6);
  num1 += num2;
  EXPECT_EQ(num1.getNumber(), 7);
}


TEST(FunnyNumberTest, Plus)
{
  FunnyNumber num1(12);
  FunnyNumber num2(2);
  FunnyNumber num3 = num1 + num2;
  EXPECT_EQ(num3.getNumber(), 6);
  FunnyNumber num4 = num2 + num3;
  EXPECT_EQ(num4.getNumber(), 7);
}
