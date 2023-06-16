cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_COMPILER "gcc-13")
set(CMAKE_CXX_COMPILER "g++-13")
project(CMakeTemplate)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
    main.cpp
    array.h
)

add_executable(main ${SOURCES})
