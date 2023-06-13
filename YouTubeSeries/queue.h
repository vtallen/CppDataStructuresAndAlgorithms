#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "linkedList.h"


template<typename T>
class LinkedListQueue {
private:
  struct Node {
    T data;
    struct Node *next;
  }; 
  
  Node *m_front{nullptr};
  Node *m_rear{nullptr};

public:
  T front() {
    if (m_front == nullptr) return T{};

    return m_front->data;
  }

  bool isEmpty() {
    return (m_front == nullptr) && (m_rear == nullptr);
  }

  void enQueue(T data) {
    Node *temp{new Node{}};

    temp->data = data;
    temp->next = nullptr;
    
    if ((m_front == nullptr) && (m_rear == nullptr)) {
      m_front = m_rear = temp;
      return;
    }

    m_rear->next = temp;
    m_rear = temp;
  }

  void deQueue() {
    // Shouldn't be needed??? 
    // Node *temp{m_front};
    if (m_front == nullptr) {
      std::cout << "The queue is empty!\n";
      return;
    }

    if (m_front == m_rear) {
      delete m_front;
      m_front = m_rear = nullptr;
    } else {
      m_front = m_front->next;
      delete m_front;
    }
  }


};



template<typename T>
class ArrayQueue {
private:
  T *m_array{};
  int m_length;
  int m_front{-1};
  int m_back{-1};

public:
  ArrayQueue(int length) : m_length{length} {
    m_array = new T[length];
  }

  ~ArrayQueue() {
    delete[] m_array;
  }

  bool isEmpty() {
    return (m_front == -1) && (m_back == -1);
  }

  bool isFull() {
    return m_back == m_length - 1;
  }
  
  T front() {
    if (isEmpty()) return T{};

    return m_array[m_front];
  }
  void enQueue(T data) {

    if (isEmpty()) {
      m_front = 0;
      m_back = 0;
    } else if (((m_back + 1) % m_length) == m_front) {
      return; 
    } else {
      m_back = (m_back + 1) % m_length;    
    }

    m_array[m_back] = data; 
  }

  T deQueue() {
    if (isEmpty()) return T{};

    T temp{m_array[m_back]};

    if (m_front == m_back) {
      m_front = -1;
      m_back = -1;
    } else {
      m_front = (m_front + 1) % m_length;
    }
    return temp;
  }
};

#endif // !QUEUE_H
#define QUEUE_H

