#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <string>
#include <vector>

// swp

// implement in c++

template <class T>
class Stack
{
public:
  Stack() : m_stack() { }
  Stack(T initialValue) : m_stack() { m_stack.push_back(initialValue); }

  void push(T value);

  T pop()
  {
    if (m_stack.empty())
      throw std::runtime_error("Stack is empty");
    T toReturn = m_stack[0];
    m_stack.erase(m_stack.begin());
    return toReturn;
  }

  void size() { m_stack.size(); }

private:
  std::vector<T> m_stack;
};

template <class T1, class T2>
T2 thirdFunction(T1& a, T1& b)
{
  std::cout << a << b << std::endl;
}

template <class T>
struct DoWork
{
  static T doWork(T value) { return value; }
};

template <>
struct DoWork<std::string>
{
  static std::string doWork(std::string value)
  {
    value.push_back('!');
    return value;
  }
};
template <>
struct DoWork<int>
{
  static int doWork(int value)
  {
    return value + 1;
  }
};

// class Stack
//{
// public:
//   Stack();
//
// private:
//   std::vector<int> m_stack;
// };

#endif
