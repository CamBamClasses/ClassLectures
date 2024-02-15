#include "Dobermann.hpp"

#include <iostream>

Dobermann::Dobermann(std::string gender, std::string name, int age)
  : Dog(gender, name), m_angry(0), m_age(age)
{
  std::cout << m_happiness << std::endl;
  std::cout << m_gender << " " << m_name << std::endl;
}

bool Dobermann::willItBiteMe() {
  int r = rand() % 10;
  if (r == 3)
    return true;
  return false;
}


void Dobermann::playFetch()
{
  m_happiness += 10;
}
