#ifndef FUNNY_NUMBER_HPP
#define FUNNY_NUMBER_HPP

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

private:
  int m_number;
};

#endif
