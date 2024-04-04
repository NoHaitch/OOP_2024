#include <iostream>

class Base {
public:
  void printStatus() {
    std::cout << "[Status] ";
    std::ostream &out = status();
    out << std::endl;
  }

private:
  virtual std::ostream &status() {
    std::ostream &out = std::cout;
    return out;
  }
};