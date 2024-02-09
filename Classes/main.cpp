#include <iostream>
#include "VendingMachine.hpp"

void printVM(VendingMachine& vm) {
  std::cout << vm.getTransactions() << std::endl;
}

int main()
{
  VendingMachine vm;
  VendingMachine vm2(size_t(100));
  VendingMachine vm3(double(101));
  VendingMachine usableVm(10, 10);

  VendingMachine vm4 = makeVm(10);

  vm.setTransactions(5);
  printVM(vm);
  ChipType myChip = vm2.buyChips();

  switch (myChip)
  {
  case ChipType::Doritors:

    break;
  case ChipType::Cheetos:

    break;
  }

  return 0;
}
