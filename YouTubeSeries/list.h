//
// Created by Vincent Allen on 4/28/23.
//

#ifndef DATASTRUCTURESANDALGORITHMS_LIST_H
#define DATASTRUCTURESANDALGORITHMS_LIST_H

#include <cassert>
#include <iostream>

template<typename T>
class List {
private:
    int m_length{};
    T *m_data{};

public:
    List() = default;

    explicit List(const int length) : m_length{length} {
        assert((length >= 0) && "Length cannot be 0 or less");
        if (length >= 0) {
            m_data = new T[length]{};
        }
    }

    List(const List<T> &list) {
        if (!m_data) { delete[] m_data; }

        m_data = new T[list.m_length];
        m_length = list.m_length;
        for (int index{0}; index < m_length; ++index) {
            m_data[index] = list[index];
        }
    }

    List<T> &operator=(const T &list) {
        if (&list == this) return *this;
        if (!m_data) { delete[] m_data; }

        m_data = new T[list.m_length];
        m_length = list.m_length;
        for (int index{0}; index < m_length; ++index) {
            m_data[index] = list[index];
        }

        return *this;
    }

    ~List() {
        if (!m_data) delete[] m_data;
    }

    T &operator[](int index) {
        assert((index >= 0) && (index < m_length) && "Index must exist");
        return m_data[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const List<T> &data) {
        for (int index{0}; index < data.m_length; ++index) {
            std::cout << data.m_data[index] << " ";
        }
        return out;
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getSize() {
        return m_length;
    }

    void resize(int newSize) {
        if ((newSize == 0) || (newSize <= m_length)) {
            return;
        }

        T *tempData{new T[newSize]};

        for (int index{0}; index < m_length; ++index) {
            tempData[index] = m_data[index];
        }
        delete[] m_data;
        m_data = tempData;
        m_length = newSize;
    }

    void insert(const T &item, int insertionIndex) {
        if ((insertionIndex < 0) || (insertionIndex >= m_length)) return;

        ++m_length;
        T *tempData{new T[m_length]};

        // Copy the data in m_data up until where we are inserting the value
        for (int index{0}; index < insertionIndex; ++index) {
            tempData[index] = m_data[index];
        }

        // Insert the element
        tempData[insertionIndex] = item;

        // Copy the rest of m_data
        for (int index{insertionIndex + 1}; index < m_length; ++index) {
            tempData[index] = m_data[index + 1];
        }

        delete[] m_data;
        m_data = tempData;
    }
};


#endif //DATASTRUCTURESANDALGORITHMS_LIST_H
