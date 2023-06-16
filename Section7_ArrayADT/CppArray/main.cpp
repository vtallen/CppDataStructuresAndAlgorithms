#include <iostream>
#include "array.h"

int main() {
  Array<int> array{5};
  array.push_back(1);
  array.push_back(2);
  array.push_back(3);
  array.push_back(3);
  std::cout << array;

  array.resize(10);
  std::cout << array;


  return 0;
}
