#include <cstddef>
#include <stdexcept>
#include <string_view>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "stack.h"

double evaluatePostfix(std::string_view expression) {
  double result{};
  LinkedListStack<double> operands;
  std::stringstream stringStream{};
  std::size_t length{expression.size()};

  for (int i{0}; i < length; ++i) {
    char currentChar{expression[i]};

    if ((currentChar == '+') || (currentChar == '-') || (currentChar == '*') || (currentChar == '/')) {
      std::cout << "operator ";

      double op2{operands.pop()};
      double op1{operands.pop()};
      
      switch(currentChar) {
        case '+':
          result += (op1 + op2);
          break;
        case '-':
          result += (op1 - op2);
          break;
        case '*':
          result += (op1 * op2);
          break;
        case '/':
          result += (op1 / op2);
          break;
        default:
          throw std::invalid_argument("An invalid postfix expression was passed");
      }

      // Skip past the next space in the string
      ++i;
      
    } else {
      if (currentChar == ' ') {
        int value{};
        stringStream >> value;
        operands.push(value);
        std::cout << "Val: " << value << '\n';
        stringStream.clear();
      } else {
        stringStream << currentChar;
      }

      
    }
  }
  
  std::cout << '\n';
  std::cout << operands;
  std::cout << result;
  return result;
}
