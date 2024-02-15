#ifndef YORKEE_HPP
#define YORKEE_HPP

#include <string>

#include "Dogs.hpp"

class Yorkee : public Dog
{
public:
  Yorkee(std::string gender, std::string m_name);

  virtual void playFetch() override;

private:
};

#endif
