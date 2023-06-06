#include <cstddef>
#include <stdexcept>
#include <string_view>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "stack.h"

std::string infixToPostfix(std::string_view expression) {
  LinkedListStack<char> operators;
  std::stringstream stringStream{};
  
  std::string resultString{};

  for (int i{0}; i < expression.length(); ++i) {
    char currentChar{expression[i]};
    
    if (!((currentChar == '+') || (currentChar == '-') || (currentChar == '*') || (currentChar == '/') || (currentChar == ' '))) {
      std::string currentNum{}; 
      while ((currentChar != ' ') && (i < expression.length()) && ((currentChar == '+') || (currentChar == '-') || (currentChar == '*') || (currentChar == '/'))) {
        currentChar = expression[i]; 
        stringStream << currentChar;
        ++i;
      } 
      
      stringStream >> currentNum;
      resultString.append(currentNum);
    } else {
      std::cout << currentChar; 
    }
  }

  return resultString;
}

double evaluatePrefix(std::string_view expression) {
  std::stringstream stringStream{};
  int length{static_cast<int>(expression.length())};
  std::cout << "Length: " << length;

  LinkedListStack<double> operands;

  for (int i{length - 1}; i >= 0; --i) {
    char currentChar{expression[i]};

    if ((currentChar == '+') || (currentChar == '-') || (currentChar == '*') || (currentChar == '/')) {
      std::cout << "Operator: " << currentChar << " ";
      double op1{operands.pop()};
      double op2{operands.pop()};
      double result{};
      
      switch(currentChar) {
        case '+':
          result = (op1 + op2);
          break;
        case '-':
          result = (op1 - op2);
          break;
        case '*':
          result = (op1 * op2);
          break;
        case '/':
          result = (op1 / op2);
          break;
        default:
          throw std::invalid_argument("An invalid postfix expression was passed");
      }
      std::cout << "Result: " << result << '\n';
      operands.push(result); 
      // Skip past the next space
      --i;
    } else {
      if (currentChar == ' ') {
        double value{};
        stringStream >> value;
        std::cout << "Val: " << value << " ";
        operands.push(value);
        stringStream.clear();
      } else {
        std::cout << "Char: " << currentChar << " ";
        stringStream << currentChar;
      }
    }
  }
  return operands.top();
}

double evaluatePostfix(std::string_view expression) {
  LinkedListStack<double> operands;
  std::stringstream stringStream{};
  std::size_t length{expression.size()};

  for (int i{0}; i < length; ++i) {
    char currentChar{expression[i]};

    if ((currentChar == '+') || (currentChar == '-') || (currentChar == '*') || (currentChar == '/')) {
      double op2{operands.pop()};
      double op1{operands.pop()};
     
      double result{};

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
      operands.push(result);
      // Skip past the next space in the string
      ++i;
      
    } else {
      if (currentChar == ' ') {
        int value{};
        stringStream >> value;
        operands.push(value);
        stringStream.clear();
      } else {
        stringStream << currentChar;
      }

      
    }
  }
  return operands.top();  
}
