cmake_minimum_required(VERSION 3.21)
project(CLinkedListBaseStack C)

set(CMAKE_C_STANDARD 99)

add_executable(CLinkedListBaseStack CLinkedList.c CLinkedList.h CLinkedListBaseStack.c CLinkedListBaseStack.h CLinkedListBaseStackMain.c)
