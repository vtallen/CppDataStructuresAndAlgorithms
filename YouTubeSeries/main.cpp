// Things to go back over
//    - Infix to postfix 4:15:00
//    - Write a destructor for classes in queue.h
//    - Write a test function for ArrayQueue

#include <cstring>
#include <iostream>
#include "list.h"

#include "linkedList.h"
#include "doublyLinkedList.h"
#include "stack.h"
#include "infixPrefixPostfix.h"
#include "queue.h"
#include "binarySearchTree.h"

void testList() {
    std::cout << "Testing list.h" << '\n';
    List<int> list(3);
    list[0] = 3;
    list[1] = 3;
    list[2] = 3;

    list.resize(10);
    std::cout << list << '\n';

    list[9] = 9;
    list.insert(8, 2);
    std::cout << list << '\n';

    List<int> listTwo;
    listTwo = list;

    std::cout << listTwo << '\n';
}

void testLinkedList() {

    LinkedList<int> linked{};
    // Testing insertion at the beginning of the list
    std::cout << "Inserting at the beginning of the list\n";
    linked.insert(12);
    std::cout << linked;
    linked.insert(18);
    std::cout << linked;
    linked.insert(2);
    std::cout << linked;
    linked.insert(6);
    std::cout << linked;

    // Testing insertion at an index
    std::cout << '\n';
    std::cout << "Inserting items at a specific index\n";
    linked.insert(1, 2);
    std::cout << linked;
    linked.insert(5, 3);
    std::cout << linked;
    linked.insert(26, 4);
    std::cout << linked;
    linked.insert(99, 4);
    std::cout << linked;

    std::cout << '\n';
    std::cout << "Reversing the list using the iterative method\n";
    linked.reverseIterative();
    std::cout << linked;

    std::cout << '\n';
    std::cout << "Reversing the list using the recursive method\n";
    linked.reverseRecursive();
    std::cout << linked;

    std::cout << '\n';
    std::cout << "Reversing the list using the explicit stack method\n";
    linked.reverseWithStack();
    std::cout << linked;
  
    std::cout << '\n';
    std::cout << "Recursive print\n";
    linked.recursivePrint();

    std::cout << '\n';
    std::cout << "Recursive reverse print";
    linked.recursiveReversePrint();
}

void testDoublyLinkedList() {
    DoublyLinkedList<int> linkedList{};

    std::cout << '\n';
    std::cout << "Inserting at head\n";
    linkedList.insertAtHead(2);
    std::cout << linkedList;

    linkedList.insertAtHead(4);
    std::cout << linkedList;

    linkedList.insertAtHead(6);
    std::cout << linkedList;

    std::cout << "\n";
    std::cout << "Inserting at tail\n";
    linkedList.insertAtTail(5);
    std::cout << linkedList;

    linkedList.insertAtTail(100);
    std::cout << linkedList;

    linkedList.insertAtTail(50);
    std::cout << linkedList;

    std::cout << '\n';
    std::cout << "Reverse printing\n";
    linkedList.reversePrint();
}

void testArrayStack() {
  ArrayStack<int> stack{5}; 
  std::cout << '\n';
  std::cout << "Pushing items\n";
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  std::cout << stack;
  std::cout << '\n';
  std::cout << "Top item " << stack.top();
  std::cout << '\n';
  std::cout << "Popping 3 items\n";
  stack.pop();
  stack.pop();
  stack.pop();
  std::cout << stack; 
  std::cout << '\n';
}

void testLinkedListStack() {
  LinkedListStack<int> stack;
  std::cout << "\nPushing items\n";
  stack.push(4);
  stack.push(6);
  stack.push(19);
  stack.push(25);
  std::cout << stack;

  std::cout << "\nPopping items\n";
  stack.pop();
  stack.pop();
  std::cout << stack;

  std::cout << "\nTop item: " << stack.top() << '\n';

}

void reverseString(char *string, int length) {
  LinkedListStack<char> stack;
  for (int i{0}; i < length; ++i) {
    stack.push(string[i]);
  }
  std::cout << stack; 
  for (int i{0}; i < length; ++i) {
    string[i] = stack.top();
    stack.pop();
  }
}

void testReverseString() {
  std::cout << "\nReversing a string: Hello World!\n";
  char string[] = "Hello World!\0";
  reverseString(string, 13);
  std::cout << string;
}

bool checkForBalancedParentheses(const char *string, int length) {
  LinkedListStack<char> stack{};
  
  for (int i{0}; i < length; ++i) {
    char currentChar{string[i]};
    if ((currentChar == '(') || (currentChar == '{') || (currentChar == '[')) stack.push(currentChar);
    else if ((currentChar == ')') || (currentChar == '}') || (currentChar == ']')) {
      if (stack.isEmpty()) return false;
      else stack.pop();
    }
  }

  return stack.isEmpty();
}

void testArrayQueue() {

  //
  ArrayQueue<int> test{10};
}

int main() {
  
  BinarySearchTree<int> bst;

  // bst.levelOrderTraversal();
  bst.insert(20);
  bst.insert(22);
  bst.insert(23);
  bst.insert(21);
  bst.insert(10);
  bst.insert(8);
  bst.insert(9);
  
  std::cout << (*bst.inOrderSuccessor(10)).data;
  bst.preOrderTraversal();
  std::cout << "min value: " << bst.min() << '\n';
  std::cout << "max value: " << bst.max() << '\n';
  std::cout << bst.isBinarySearchTree();

  std::cout << '\n';
  
  bst.deleteNode(10);
  bst.deleteNode(22);
  bst.deleteNode(20);
  bst.inOrderTraversal();

  return 0;
}
