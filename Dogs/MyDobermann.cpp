#include "MyDobermann.hpp"

#include <iostream>

MyDobermann::MyDobermann(std::string gender, std::string name)
  : Dobermann(gender, name), m_angry(0)
{
}

bool MyDobermann::willItBiteMe()
{
  return false;
}
