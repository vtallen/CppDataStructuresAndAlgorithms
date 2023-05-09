//
// Created by vtallen on 5/4/23.
//

#ifndef DATASTRUCTURESANDALGORITHMS_DOUBLYLINKEDLIST_H
#define DATASTRUCTURESANDALGORITHMS_DOUBLYLINKEDLIST_H
#include <iostream>

template<typename T>
class DoublyLinkedList {
private:
    class Node {
    public:
        T data;
        struct Node *next;
        struct Node *prev;

        Node() = default;

        Node(const Node &node) {
            data = node.data;
            next = node.next;
            prev = node.prev;
        }

        Node &operator=(const Node &node) {
            if (&node == this) return this;
            data = node.data;
            next = node.next;
            prev = node.prev;
            return this;
        }

        ~Node() = default;
    };

private:
    Node *m_head{nullptr};

    Node *getNewNode(T data) {
        Node *newNode{new Node};
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

public:
    DoublyLinkedList() = default;

    ~DoublyLinkedList() = default;

    friend std::ostream &operator<<(std::ostream &out, DoublyLinkedList<T> &node) {
        Node *temp{node.m_head};

        std::cout << "DoublyLinkedList: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
        return out;
    }

    void reversePrint() {
        Node *temp{m_head};
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        std::cout << "DoublyLinkedList Reverse: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << '\n';
    }

    void insertAtHead(const T data) {
        Node *newNode{getNewNode(data)};

        if (m_head == nullptr) {
            m_head = newNode;
            return;
        }

        m_head->prev = newNode;
        newNode->next = m_head;
        m_head = newNode;
    }

    void insertAtTail(const T data) {
        Node *newNode{new Node};
        newNode->data = data;

        Node *temp{m_head};
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
    }


};


#endif //DATASTRUCTURESANDALGORITHMS_DOUBLYLINKEDLIST_H
