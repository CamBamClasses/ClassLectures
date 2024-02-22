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

TEST(FunnyNumberTest, Divide)
{
  FunnyNumber num1(12);
  FunnyNumber num2(2);
  FunnyNumber num3 = num1 / num2;
  EXPECT_EQ(num3.getNumber(), 12);
  FunnyNumber num5(3);
  FunnyNumber num4 = num3 / num5;
  EXPECT_EQ(num4.getNumber(), 6);
}

TEST(FunnyNumberTest, DivideBy0)
{
  FunnyNumber num1(12);
  FunnyNumber num2(1);
  EXPECT_THROW(num1 / num2, std::exception);
}

TEST(FunnyNumberTest, AssignmentOperator)
{
  FunnyNumber num1(12);
  FunnyNumber num2(1);
  num2 = num1;
  EXPECT_EQ(num2.getNumber(), 23);
}

TEST(FunnyNumberTest, Minus)
{
  FunnyNumber num1(12);
  FunnyNumber num2(2);
  num1 -= num2;
  EXPECT_EQ(num1.getNumber(), 32);
}

TEST(FunnyNumberTest, Insertion)
{
  std::stringstream ss1;
  std::stringstream ss2;
  std::stringstream ss3;
  FunnyNumber num1(13);
  FunnyNumber num2(2);
  FunnyNumber num3(6);
  ss1 << num1;
  ss2 << num2;
  ss3 << num3;
  EXPECT_EQ(ss1.str(), "12a");
  EXPECT_EQ(ss2.str(), "1b");
  EXPECT_EQ(ss3.str(), "5c");
}

TEST(FunnyNumberTest, LessThan)
{
  FunnyNumber num1(13);
  FunnyNumber num2(2);
  EXPECT_TRUE(num2 < num1);
  EXPECT_FALSE(num2 < num2);
}


TEST(DoubleTest, CompareDoubles)
{
  double a = 3; // 3.000000000000000000001
  double b = 3; // 3.000000000000000000003
  double delta = .000001;

  EXPECT_TRUE(std::abs(a - b) < delta);
}
