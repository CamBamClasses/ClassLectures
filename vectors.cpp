#include <iostream>
#include <vector>

int main()
{

  std::vector<int> numbers(10, 1);
  std::vector<int> numbers2(10, 1);

  for (size_t i = 0; i < numbers.size(); i++)
  {
    numbers[i] = i;
    numbers.at(i) = i;
    // std::cout << numbers[i] << " ";
    // std::cout << numbers.at(i) << std::endl;
  }

  numbers.push_back(10);
  numbers.push_back(11);
  numbers.push_back(12);
  numbers.pop_back();
  numbers.erase(numbers.begin() + 2);

  numbers.erase(numbers.begin(), numbers.begin() + 2);
  numbers.clear();

  if (numbers == numbers2)
  {
    std::cout << "the same!" << std::endl;
  }
  std::vector<int> numbers3 = numbers;

  return 0;
}