#include "FunnyNumber.hpp"

FunnyNumber::FunnyNumber() : m_number(12) { }
FunnyNumber::FunnyNumber(int val) : m_number(val - 1) { }

int FunnyNumber::getNumber()
{
  return m_number;
}

bool FunnyNumber::operator==(FunnyNumber& rhs)
{
  return m_number == rhs.m_number;
}

bool FunnyNumber::operator==(int rhs)
{
  return m_number == rhs;
}

FunnyNumber& FunnyNumber::operator+=(FunnyNumber const& rhs)
{
  m_number += rhs.m_number;
  if (m_number % 2 == 0)
  {
    m_number /= 2;
  }
  return *this;
}

FunnyNumber operator+(FunnyNumber lhs, FunnyNumber const& rhs)
{
  lhs += rhs;
  return lhs;
}
