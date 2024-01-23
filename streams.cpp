#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  double pi = 3.141592654;

  std::cout << std::setw(10) << std::setprecision(3) << "3.1" << std::endl;
  std::cout << std::setw(10) << std::setprecision(3) << "3.24" << std::endl;
  std::cout << std::setw(10) << std::setprecision(3) << pi << std::endl;

  double bigNumber = 164;

  // std::cout << std::fixed << bigNumber << " " << std::scientific << bigNumber
  //           << std::endl;  //std::cout << std::fixed << bigNumber << " " <<
  //           std::scientific << bigNumber
  //           << std::endl;

  std::cout << bigNumber << std::endl;

  bool isTrue = true;
  bool isFalse = false;

  std::cout << std::boolalpha << isTrue << std::endl;
  std::cout << std::boolalpha << isFalse << std::endl;

  std::string firstString;
  char a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a << b << c << std::endl;

  std::getline(std::cin, firstString);
  // std::cout << firstString << std::endl;

  std::ofstream fout;
  std::ofstream fout2;

  if (fout.good())
  {
    std::cout << "opened output file" << std::endl;
  }

  fout.open("output.txt", std::fstream::app);
  fout2.open("output2.txt", std::fstream::app);

  fout << a << b << c << std::endl;

  fout.close();

  std::ifstream fin("input.txt");

  if (!fin)
  {
    throw std::runtime_error("Invalid input file");
  }

  while (!fin.eof())
  {
    std::string line;
    std::getline(fin, line);
    std::cout << line << std::endl;
  }

  std::string line;
  std::getline(fin, line);
  std::cout << line << std::endl;

  return 0;
}
