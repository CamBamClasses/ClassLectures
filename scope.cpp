#include <iostream>

namespace test
{
  int j;
}

int doWork(int i)
{
  test::j++;
  if (i == 0)
  {
    int k = i;
  }
  k++; // can't do this!
  std::cout << i << std::endl;
  return 0;
}

int doWork2(int i)
{
  std::cout << i << std::endl;
  return 0;
}

int main()
{
  int m = 0;
  doWork2(m);
  i++; // can't do this
  return 0;
}
