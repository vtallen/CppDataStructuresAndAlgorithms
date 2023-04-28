#include <iostream>
#include "list.h"

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

    std::cout << listTwo <<'\n';
}

int main() {
    // Testing list.h
    testList();
    return 0;
}
