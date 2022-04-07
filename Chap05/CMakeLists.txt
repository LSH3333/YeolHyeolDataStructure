cmake_minimum_required(VERSION 3.21)
project(Chap05 C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap05 CLinkedList.c CLinkedList.h CLinkedMain.c)
