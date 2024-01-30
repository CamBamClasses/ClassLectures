#include <iostream>
#include <vector>
#include <thread>

struct Node
{
  std::string key;
  int value;
};

int main()
{
  std::vector<int> numbers(10, 1);
  std::vector<int> numbers2(10, 1);
  const auto myNumber = 3;
  auto secondNumber = myNumber;
  auto numbers4 = numbers;

  for (size_t i = 0; i < numbers.size(); i++)
  {
    numbers[i] = i;
    numbers.at(i) = i;
    // std::cout << numbers[i] << " ";
    // std::cout << numbers.at(i) << std::endl;
  }

  for (auto itr = numbers.begin(); itr != numbers.end(); itr++)
  {
    std::cout << *itr << std::endl;
  }

  for (auto&& itr : numbers)
  {
    std::cout << itr << std::endl;
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

  std::vector<Node> nodes;

  nodes.emplace_back("test", 4);

  for (auto&& itr : nodes)
  {
    std::cout << itr.key << " " << itr.value << std::endl;
  }

  std::vector<std::vector<int>> dVector(4, std::vector<int>(4, 3));
  dVector[0][0];

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  return 0;
}