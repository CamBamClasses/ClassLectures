#include <iostream>


namespace example1 {
  void doWork() {
    std::cout << "No, i'm lazy" << std::endl;
  }
}

namespace example2 {
  void doWork() {
    std::cout << "Sure!!" << std::endl;
  }
}

namespace {
  void doWork() {
    throw std::runtime_error("You can't do that");

    std::cout << "Sure!!" << std::endl;
  }
}

class IncorrectParameters : public std::runtime_error
{
public:
  IncorrectParameters() : std::runtime_error("Invalid input parameters") {};
  int getCode() { return 1; }
};

int main() {
  example1::doWork();
  example2::doWork();

  try {
    doWork();
    throw IncorrectParameters();
    throw std::runtime_error("You can't do that");
    throw int(4);
    throw std::string("");
    throw double(4);
  }
  catch (std::exception err) {
    std::cout << err.what() << std::endl;
  }
  catch (...) {

  }

  return 0;
}
