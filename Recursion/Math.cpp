#include "Math.hpp"

#include <iostream>

int math::sigmaNum(int val)
{
  if (val <= 0)
    return 0;

  return val + sigmaNum(val - 1);
}

int math::fibonacci(int val, std::vector<int>& myCache)
{
  static int calls = 0;
  calls++;
  std::cout << calls << std::endl;

  if (val <= 0)
    return 0;

  if (myCache.size() <= val)
    myCache.resize(val + 1);

  if (myCache[val] != 0)
    return myCache[val];

  if (val == 1 || val == 2)
  {
    myCache[val] = 1;
    return 1;
  }
  return myCache[val] =
           (fibonacci(val - 1, myCache) + fibonacci(val - 2, myCache));
}
