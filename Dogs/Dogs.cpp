#include "Dogs.hpp"

Dog::Dog(std::string gender, std::string name)
  : m_happiness(0), m_gender(gender), m_name(name)
{
  dogsCreated++;
}

void Dog::feed(int food)
{
  m_happiness += food;
}

size_t Dog::dogsCreated = 0;

//void Dog::passDay()
//{
//  m_happiness -= 5;
//}
