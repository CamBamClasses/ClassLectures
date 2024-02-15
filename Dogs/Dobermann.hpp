#ifndef DOBERMANN_HPP
#define DOBERMANN_HPP

#include <string>

#include "Dogs.hpp"

class Dobermann : public Dog
{
public:
  Dobermann(std::string gender, std::string m_name, int age);

  virtual bool willItBiteMe();

  virtual void playFetch() override;


private:
  int m_age;
  double m_angry;
};

#endif
