//
// Created by vtallen on 4/28/23.
//

#ifndef DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H
#define DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H

#include <iostream>
#include "stack.h"
template<typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node *next;

        Node(const T &inputData, Node *inputNext) : data{inputData}, next{inputNext} {}

        Node() {
            data = {};
            next = nullptr;
        }

        Node(const Node &n) {
            data = n.data;
            next = n.next;
        }

        ~Node() = default;
    };

private:
    Node *m_head{nullptr};

public:
    LinkedList() = default;

    explicit LinkedList(const T &initData) : m_head{new Node{initData, nullptr}} {}

private:
    void deallocateLink(Node *node) {
        if (node->next == nullptr) return;
        deallocateLink(node->next);
    }

public:
    ~LinkedList() {
        deallocateLink(m_head);
    }

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
        Node *temp{new Node{}};
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

    void remove(int index) {
        Node *previousNode{m_head};

        if (index == 0) {
            m_head = previousNode->next;
            delete previousNode;
            return;
        }

        for (int i{0}; i < index - 1; ++i) {
            previousNode = previousNode->next;
        }
        Node *nodeToDelete{previousNode->next};
        previousNode->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void reverseIterative() {
        Node *current{m_head};
        Node *next{};
        Node *previous{nullptr};
        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        m_head = previous;
    }

public:
    void reverseRecursive() { privateReverseRecursive(m_head); }

private:
    void privateReverseRecursive(Node *node) {
        if (node->next == nullptr) {
            m_head = node;
            return;
        }
        privateReverseRecursive(node->next);
        Node *q{node->next};
        q->next = node;
        node->next = nullptr;
    }

public:
    void recursivePrint() { privateRecursivePrint(m_head); }

    void recursiveReversePrint() { privateRecursiveReversePrint(m_head); }

private:
    void privateRecursivePrint(Node *head) {
        if (head == nullptr) {
            std::cout << '\n';
            return;
        }
        std::cout << head->data << " ";
        privateRecursivePrint(head->next);
    }

    void privateRecursiveReversePrint(Node *head) {
        if (head == nullptr) {
            std::cout << '\n';
            return;
        }
        privateRecursiveReversePrint(head->next);
        std::cout << head->data << " ";
    }
public:
  void reverseWithStack() {
    if (m_head == nullptr) return;
    LinkedListStack<Node*> stack;
    Node *temp{m_head};
    while (temp != nullptr) {
      stack.push(temp);
      temp = temp->next;
    }

    temp = stack.top();
    m_head = temp;
    stack.pop();
    while (!stack.isEmpty()) {
      temp->next = stack.top();
      stack.pop();
      temp = temp->next;
    }
    temp->next = nullptr; 
  }
};

#endif //DATASTRUCTURESANDALGORITHMS_LINKEDLIST_H
