#include "MyDobermann.hpp"

#include <iostream>

MyDobermann::MyDobermann(std::string gender, std::string name)
  : Dobermann(gender, name, 5), m_angry(0)
{
}

bool MyDobermann::willItBiteMe()
{
  return false;
}

void MyDobermann::feed(int food) {
  std::cout << "Thats good food, but it's not your food" << std::endl;
}
