#include "Ptrs.hpp"
#include "gtest/gtest.h"

void doWork(SmartPtr ptr)
{
  std::cout << ptr.getVal() << std::endl;
}

void doWork(std::unique_ptr<std::string>& ptr)
{
  if (ptr != nullptr)
  {
    std::cout << *ptr << std::endl;
    // auto a = ptr.get();
  }
}

void doWork(std::shared_ptr<std::string> ptr)
{
  if (ptr != nullptr)
  {
    std::cout << *ptr << std::endl;
    // auto a = ptr.get();
  }
}

TEST(SmartPtrTest, Test0)
{
  SmartPtr ptr(5);
  doWork(ptr);
  std::cout << ptr.getVal() << std::endl;
}

TEST(UniquePtrTest, Test0)
{
  auto ptr =
    std::make_unique<std::string>("March Madess is awesome! but i'm losing");
  doWork(ptr);
}

TEST(SharedPtrTest, Test0)
{
  auto ptr =
    std::make_shared<std::string>("March Madess is awesome! but i'm losing");
  doWork(ptr);
  //auto ptr2 = std::shared_ptr<std::string>(new std::string("why?"));
  std::weak_ptr<std::string> ptr2(ptr);

  int* a = new int(3);

  if (a != nullptr)
  {
    std::cout << *a << std::endl;
  }

  auto ptr3 = ptr2.lock();
  std::cout << *ptr3 << std::endl;
}

TEST(ExceptionTest, Test0)
{
  try
  {
    throw DuhException("I don't know");
  }
  catch (DuhException e)
  {
    e.please();
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
  catch (...)
  {
  }
}
