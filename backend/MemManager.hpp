#include "FNum.hpp"

class MemManager {
 public:
  FNum& operator[](int index) { return registers[index]; }

 private:
  FNum registers[8];
};