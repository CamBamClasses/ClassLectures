#ifndef VENDING_MACHINE_HPP
#define VENDING_MACHINE_HPP

#include <vector>

enum class ChipType
{
  None,
  Doritors,
  VickisJalepeno,
  Pringles,
  Ruffles,
  SunChips,
  Cheetos,
};

class VendingMachine
{
public:
  VendingMachine(); // default constructor

  // parameter constructor
  explicit VendingMachine(double money);
  explicit VendingMachine(size_t);
  // VendingMachine(size_t chips, double money);
  VendingMachine(size_t chips, size_t drinks);

  // copy constructor
  VendingMachine(VendingMachine& vm) = delete;

  VendingMachine(VendingMachine&& vm);

  ~VendingMachine();

  VendingMachine(const size_t& m_transactions,
                 const size_t& m_chips,
                 const size_t& m_drinks,
                 double m_money);

  size_t getTransactions();
  void setTransactions(size_t transactions);

  size_t getChips();
  void addChips(size_t chips);

  double insertMoney(double money);

  ChipType buyChips();
  size_t buyChips(size_t amountOfChips);

private:
  size_t m_transactions;
  size_t m_chips;
  size_t m_drinks;
  double m_money;
  double m_thisTransaction;
};

VendingMachine makeVm(size_t drinks);

#endif
