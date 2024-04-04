#ifndef PTRS_HPP
#define PTRS_HPP

#include <memory>
#include <string>

// unique_ptr
// shared_ptr
// weak_ptr


class DuhException : public std::exception
{
public:
  DuhException(std::string msg);

  void please();

private:
  std::string m_msg;
};

class SmartPtr
{
public:
  SmartPtr(int val);

  ~SmartPtr();

  SmartPtr(SmartPtr&);

  int getVal();

private:
  int* m_ptr;

  int* m_count;
};

#endif
