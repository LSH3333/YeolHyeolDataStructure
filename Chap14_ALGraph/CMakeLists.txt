cmake_minimum_required(VERSION 3.21)
project(Chap14_ALGraph C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap14_ALGraph DLinkedList.h DLinkedList.c ALGraph.c ALGraph.h)
