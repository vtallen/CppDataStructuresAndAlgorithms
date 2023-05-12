cmake_minimum_required(VERSION 3.25)
project(DataStructuresAndAlgorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(main
  main.cpp 
  list.h 
  linkedList.h 
  doublyLinkedList.h
  stack.h

  infixPrefixPostfix.cpp
  infixPrefixPostfix.h

  queue.h
)
