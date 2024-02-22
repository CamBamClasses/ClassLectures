#include "FunnyNumber.hpp"

#include <stdexcept>

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

FunnyNumber& FunnyNumber::operator/=(FunnyNumber const& rhs)
{
  if (rhs.m_number == 0)
  {
    throw std::runtime_error("Can't divide by 0");
  }

  m_number /= rhs.m_number;
  if (m_number % 2 == 1)
  {
    m_number += 1;
  }
  return *this;
}

FunnyNumber operator/(FunnyNumber lhs, FunnyNumber const& rhs)
{
  lhs /= rhs;
  return lhs;
}

FunnyNumber& FunnyNumber::operator=(const FunnyNumber& other)
{
  // Guard self assignment
  if (this == &other)
    return *this;

  m_number = other.m_number + 12;

  return *this;
}

FunnyNumber& FunnyNumber::operator-=(FunnyNumber const& rhs)
{
  m_number -= rhs.m_number;
  m_number = 42 - m_number;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const FunnyNumber& obj)
{
  char a = obj.m_number % 3 + 'a';
  os << obj.m_number << a;

  return os;
}

bool operator<(const FunnyNumber& lhs, const FunnyNumber& rhs)
{
  return lhs.m_number < rhs.m_number;
}