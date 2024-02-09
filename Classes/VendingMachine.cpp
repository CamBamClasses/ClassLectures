#include "VendingMachine.hpp" // PAIRED INCLUDE

#include <iostream>

const double COST_OF_CHIPS = 2.5;

VendingMachine::VendingMachine()
  // initializer list
  : m_transactions(0), m_chips(0), m_drinks(0), m_money(0), m_thisTransaction(0)
{
}

VendingMachine::VendingMachine(double money)
{
  m_transactions = 0;
  m_chips = 0;
  m_drinks = 0;
  m_money = money;
  m_thisTransaction = 0;
}

// VendingMachine::VendingMachine(size_t chips, double money)
//   : m_transactions(0), m_chips(chips), m_drinks(0), m_money(money)
//{
// }

VendingMachine::VendingMachine(size_t chips, size_t drinks)
  : m_transactions(0),
    m_chips(chips),
    m_drinks(drinks),
    m_money(0),
    m_thisTransaction(0)
{
}

VendingMachine::VendingMachine(size_t chips)
  : m_transactions(0),
    m_chips(chips),
    m_drinks(0),
    m_money(0),
    m_thisTransaction(0)
{
}

VendingMachine::VendingMachine(VendingMachine&& vm)
  : m_transactions(vm.m_transactions),
    m_chips(vm.m_chips),
    m_drinks(vm.m_drinks),
    m_money(vm.m_money),
    m_thisTransaction(0)
{
}

VendingMachine::VendingMachine(const size_t& m_transactions,
                               const size_t& m_chips,
                               const size_t& m_drinks,
                               double m_money)
  : m_transactions(m_transactions),
    m_chips(m_chips),
    m_drinks(m_drinks),
    m_money(m_money),
    m_thisTransaction(0)
{
}

VendingMachine::~VendingMachine()
{
  std::cout << "You made " << m_transactions << " money!" << std::endl;
}

size_t VendingMachine::getTransactions()
{
  return m_transactions;
}

void VendingMachine::setTransactions(size_t transactions)
{
  m_transactions = transactions;
}

VendingMachine makeVm(size_t drinks)
{
  return VendingMachine(0, drinks);
}

size_t VendingMachine::getChips()
{
  return m_chips;
}

void VendingMachine::addChips(size_t chips)
{
  m_chips += chips;
}

double VendingMachine::insertMoney(double money)
{
  if (money < 0)
  {
    std::cout << "You can't deposit negative" << std::endl;
    return m_thisTransaction;
  }

  m_thisTransaction += money;
}

ChipType VendingMachine::buyChips()
{
  if (!m_chips)
  {
    std::cout << "You can't buy chips cause we don't have any" << std::endl;
    return ChipType::None;
  }
  if (m_thisTransaction < COST_OF_CHIPS)
  {
    std::cout << "You can't buy chips cause you don't have the money"
              << std::endl;
    return ChipType::None;
  }
  m_chips--;
  m_thisTransaction -= COST_OF_CHIPS;
  m_money += COST_OF_CHIPS;
  m_transactions++;
  if (m_transactions % 2)
  {
    return ChipType::VickisJalepeno;
  }
  return ChipType::Doritors;
}

size_t VendingMachine::buyChips(size_t amountOfChips) 
{
  for (size_t i = 0; i < amountOfChips; i++)
  {
    if (!buyChips())
    {
      return i;
    }
  }
}
