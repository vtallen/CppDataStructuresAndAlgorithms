#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <iostream>
#include <cassert>
#include <memory>
template <typename T>
class Array {
private:
  int m_length{};
  int m_size{};
  T* m_arr{};

public:
  Array(int size) : m_size{size} {
    m_arr = new T[m_size]; 
    m_length = 0;
  }

  ~Array() {
    delete[] m_arr;
  }

  friend std::ostream &operator<<(std::ostream &out, Array &array) {
    for (int i{0}; i < array.m_length; ++i) {
      out << array.m_arr[i] << " "; 
    }

    out << '\n';

    return out;
  }

  int& operator[](std::size_t index) {
    return m_arr[index];
  }
  
  T &at(std::size_t index) {
    if (index < m_length) return m_arr[index]; 
  }
  
  void resize(std::size_t newSize) {
    if (newSize <= m_size) return;
    T* newArr = new T[newSize];
    
    for (int i{0}; i < m_length; ++i) {
      newArr[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = newArr;
  }

  void push_back(T data) {
    if (m_length == m_size) return;
    m_arr[m_length] = data;
    m_length++;
  }

  void insert(std::size_t index, T data) {
    if (m_length == m_size) resize(m_length * 2); // resize(arr, arr.size * 2)

    for (int i{m_length}; i > index; --i) {
      m_arr[i + 1] = m_arr[i];
    }

    m_arr[index] = data;
    ++m_length;
  }

  void del(std::size_t index) {
    if (index >= m_length) return;
    
    for (std::size_t i{index}; i < m_length; ++i) {
      m_arr[i] = m_arr[i + 1];
    }

    --m_length;
  std::cout <<"Got here";
  }

  T pop() {
    return m_arr[m_length--];
  }

  bool swap(std::size_t i, std::size_t j) {
    if ((i > m_length) || (j > m_length)) return false;

    T temp{m_arr[i]};
    m_arr[i] = m_arr[j];
    m_arr[j] = temp;

    return true;
  }

  int search(const T &data) {
    for (int i{0}; i < m_length; ++i) {
      if (m_arr[i] == data) return i;
    }

    return -1;
  }

  int binarySearch(const T &data) {
    
    int l = 0;
    int h = m_length;
    int mid = 0;

    while (l <= h) {
      mid = (l + h) / 2;
      if (m_arr[mid] == data) return mid;
      else if (data < m_arr[mid]) h = mid - 1;
      else if (data > m_arr[mid]) l = mid - 1;
    }

    return -1;
  }

  void set(std::size_t index, T &data) {
    if (index > m_length) return;
    m_arr[index] = data;
  }

  
  int max() {
    int maxN = 0;
    for (int i = 0; i < m_length; ++i) {
      if (m_arr[i] > maxN) maxN = m_arr[i];
    }
    return maxN;
  }

};
#endif
