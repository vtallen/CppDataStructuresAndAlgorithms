// Need to add copy constructors
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

template<typename T>
class LinkedListStack {
private:
  struct Node {
    T data;
    Node *next;
  };

  Node *m_top{nullptr};

public:
  LinkedListStack() {

  }

  ~LinkedListStack() {
    Node *temp{m_top};
    Node *next{};
    while (temp != nullptr) {
      next = temp->next;
      delete temp;
      temp = next;
    }
  }

  friend std::ostream &operator<<(std::ostream &out, LinkedListStack<T> &stack) {
    Node *temp{stack.m_top};
    while (temp != nullptr) {
      out << temp->data << " ";
      temp = temp->next;
    }
    return out;
  }

  void push(const T data) {
    Node *temp{new Node{}};
    temp->data = data;
    temp->next = m_top;
    m_top = temp;
  }
  
  void pop() {
    if (m_top == nullptr) return;
    Node *temp{m_top};
    m_top = m_top->next;
    delete temp;
  }

  T top() {
    if (m_top == nullptr) return T{};
    return m_top->data;
  }


};

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
  
  ~ArrayStack() {
    delete[] m_array;
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
  void push(const T data) {
    // Unsure if I need to subtrack 1 from m_arraySize
    if (m_top == m_arraySize - 1) {
      std::cout << "Stack is full, data not pushed onto the stack\n";
    }
    
    m_array[++m_top] = data;
  }
  
};




#endif
