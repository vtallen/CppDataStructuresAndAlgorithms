//
// Created by vtallen on 4/28/23.
//

#ifndef DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H
#define DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node *next;
    };
private:
    Node *m_head{nullptr};

public:
    LinkedList() {}

    explicit LinkedList(const T &initData) : m_head{new Node{initData, nullptr}} {}

    friend std::ostream &operator<<(std::ostream &out, LinkedList<T> list) {
        std::cout << "LinkedList: ";
        Node *temp{list.m_head};
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';

        return out;
    }

    void insert(const T &data) {
        Node *tempNode{new Node{}};
        tempNode->data = data;
        if (m_head != nullptr) tempNode->next = m_head;
        m_head = tempNode;
    }

    void insert(const T &data, int index) {
        Node *temp{new Node()};
        temp->data = data;
        temp->next = nullptr;

        if (index == 0) {
            if (m_head != nullptr) {
                temp->next = m_head;
                m_head = temp;
            } else {
                m_head = temp;
            }
            return;
        }

        Node *currentNode{m_head};
        for (int i{0}; i < index - 1; ++i) {
            currentNode = currentNode->next;
            if (currentNode->next == nullptr) throw std::invalid_argument("Index out of bounds");
        }
        temp->next = currentNode->next;
        currentNode->next = temp;


    }


    void print() {
        Node *temp{m_head};
        while (temp != nullptr) {
            std::cout << temp->data;
            temp = temp->next;
        }
    }
};

#endif //DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H
