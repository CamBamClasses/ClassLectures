#ifndef DOGS_HPP
#define DOGS_HPP

#include <string>

class Dog
{
public:
  Dog(std::string gender, std::string m_name);

  virtual void playFetch() = 0;
  virtual void playFetch(int minutes) = 0;

  virtual void feed(int food);

  double m_happiness;

protected:
  static size_t dogsCreated;

  std::string m_gender;
  std::string m_name;
};

#endif
