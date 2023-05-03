#include <iostream>
#include "list.h"
#include "linkedList.h"

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
    std::cout << "Recursive print\n";
    linked.recursivePrint();

    std::cout << '\n';
    std::cout << "Recursive reverse print";
    linked.recursiveReversePrint();
}

int main() {
    // Testing list.h
    //  testList();

    // Testing linkedList.h
    testLinkedList();


    return 0;
}
