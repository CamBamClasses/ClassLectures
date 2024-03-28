#include "Templates.hpp"

template <class T>
void Stack<T>::push(T value)
{
  m_stack.push_back(value);
}
