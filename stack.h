#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

template<typename T>
class ArrayStack {
private:
  T *m_array {nullptr};
  int m_arraySize{};
  int m_top{-1};

public:
  ArrayStack() = delete;
  ArrayStack(int size) : m_arraySize{size} {
    if (size <= 0) throw std::runtime_error("Cannot create a stack with size less than 1.");
    m_array = new T[size];
  }

  ArrayStack(ArrayStack<T> &stack) {
    
  }

  ArrayStack<T> operator==(ArrayStack<T> &stack) {
    
  }
  
  friend std::ostream &operator<<(std::ostream &out, ArrayStack<T> &stack) {
    for (int i{stack.m_top}; i >= 0; --i) {
      out << stack.m_array[i] << " ";
    }   
    out << '\n';
    return out;
  }

  T top() {
    if (m_top == -1) std::cout << "Stack is empty";
    return m_array[m_top];
  }
  
  void pop() {
    if (m_top == -1) {
      std::cout << "No element to pop";
      return;
    }
    --m_arraySize;
    --m_top;
  }
  void push(T data) {
    // Unsure if I need to subtrack 1 from m_arraySize
    if (m_top == m_arraySize - 1) {
      std::cout << "Stack is full, data not pushed onto the stack\n";
    }
    
    m_array[++m_top] = data;
  }
  
};




#endif
