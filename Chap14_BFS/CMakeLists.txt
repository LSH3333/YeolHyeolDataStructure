cmake_minimum_required(VERSION 3.21)
project(Chap14_BFS C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap14_BFS BFSMain.c ALGraphBFS.c ALGraphBFS.h CircularQueue.c CircularQueue.h DLinkedList.h DLinkedList.c)
