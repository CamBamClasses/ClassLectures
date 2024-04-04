#include "Ptrs.hpp"

DuhException::DuhException(std::string msg) : exception(), m_msg(msg) { }

void DuhException::please()
{

}

SmartPtr::SmartPtr(int val) : m_ptr(new int(val)), m_count(new int(1)) { }

SmartPtr::SmartPtr(SmartPtr& ptr)
{
  m_ptr = ptr.m_ptr;
  m_count = ptr.m_count;

  (*m_count)++;
}

SmartPtr::~SmartPtr()
{
  (*m_count)--;
  if ((*m_count) == 0)
  {
    delete m_ptr;
    delete m_count;
  }
}

int SmartPtr::getVal()
{
  return *m_ptr;
}
