#include <iostream>
#include <vector>

#include "Dobermann.hpp"
#include "Yorkee.hpp"

void printHappiness(Dog* ourDog)
{
  std::cout << ourDog->m_happiness << std::endl;
  ourDog->playFetch();
  ourDog->feed(4);
}

int main()
{
  Dobermann fido("male", "Fido");
  Yorkee snoopy("male", "Snoopy");
  //fido.dogsCreated == snoopy.dogsCreated;

  double* pOurDouble = new double(0);
  int* pOurInt = new int(0);
  std::vector<int>* myVector = new std::vector<int>();
  std::vector<int>* myVector2 = new std::vector<int>[4];
  myVector->push_back(4);

  Dobermann* dobby = new Dobermann("male", "Dobby");
  Yorkee* mrTibs = new Yorkee("male", "mrTibs");
  printHappiness(dobby);
  printHappiness(mrTibs);

  delete pOurDouble;
  delete pOurInt;
  delete myVector;
  delete[] myVector2;
  delete dobby;

  return 0;
}
