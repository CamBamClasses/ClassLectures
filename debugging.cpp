#include <iostream>

void printAstrisk()
{
  std::cout << "*";
}

int main(int argc, char* argv[])
{
  //int* a = nullptr;
  //a[3] = 3;
  for (int i = 0; i < 10; i++)
  {
    for (int j = i; j < 10; j++)
    {
      printAstrisk();
    }
    //if (i == 9)
    //  throw std::runtime_error("Last row");
    std::cout << std::endl;
  }

  return 0;
}
