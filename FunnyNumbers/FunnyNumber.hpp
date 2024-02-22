#ifndef FUNNY_NUMBER_HPP
#define FUNNY_NUMBER_HPP

#include <iostream>

class FunnyNumber
{
public:
  FunnyNumber();

  explicit FunnyNumber(int);

  int getNumber();

  // tests if equal
  bool operator==(FunnyNumber& rhs);
  bool operator==(int rhs);

  FunnyNumber& operator+=(FunnyNumber const& rhs);
  friend FunnyNumber operator+(FunnyNumber lhs, FunnyNumber const& rhs);

  FunnyNumber& operator/=(FunnyNumber const& rhs);
  friend FunnyNumber operator/(FunnyNumber lhs, FunnyNumber const& rhs);

  FunnyNumber& operator=(FunnyNumber const& other);

  FunnyNumber& operator-=(FunnyNumber const& rhs);

  friend std::ostream& operator<<(std::ostream& os, const FunnyNumber& obj);

  friend bool operator<(const FunnyNumber& lhs, const FunnyNumber& rhs);

private:
  int m_number;
};

#endif
