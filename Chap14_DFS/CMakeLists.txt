cmake_minimum_required(VERSION 3.21)
project(Chap14_DFS C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap14_DFS DFSMain.c ALGraphDFS.h ALGraphDFS.c ArrayBaseStack.c ArrayBaseStack.h DLinkedList.c DLinkedList.h)
