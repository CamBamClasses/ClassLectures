#include <iostream>
#include <array>

int main() {
  std::array<double, 5> myArray = {};
  std::array<double, 5> secondArray = {};
  std::array<double, 5> thirdArray = myArray;

  for (size_t i = 0; i < myArray.size(); i++)
  {
    myArray[i] = i;
    std::cout << myArray[i] << std::endl;
  }

  if (myArray == secondArray)
  {
  
  }

  return 0;
}
