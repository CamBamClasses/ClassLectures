#ifndef MY_DOBERMANN_HPP
#define MY_DOBERMANN_HPP

#include <string>

#include "Dobermann.hpp"

class MyDobermann : public Dobermann
{
public:
  MyDobermann(std::string gender, std::string m_name);

 virtual bool willItBiteMe() override;


private:
  double m_angry;
};

#endif
