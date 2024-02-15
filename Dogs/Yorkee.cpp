#include "Yorkee.hpp"

Yorkee::Yorkee(std::string gender, std::string name)
  : Dog(gender, name)
{
}


void Yorkee::playFetch()
{
  m_happiness += 1;
}
