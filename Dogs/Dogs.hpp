#ifndef DOGS_HPP
#define DOGS_HPP

#include <string>

class Dog
{
public:
  Dog(std::string gender, std::string m_name);

  virtual void playFetch() = 0;

  void feed(int food);

  static size_t dogsCreated;

  double m_happiness;
private:
  std::string m_gender;
  std::string m_name;
};

#endif
