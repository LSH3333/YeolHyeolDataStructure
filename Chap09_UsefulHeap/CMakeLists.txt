cmake_minimum_required(VERSION 3.21)
project(Chap09_UsefulHeap C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap09_UsefulHeap UsefulHeap.c UsefulHeap.h UsefulHeapMain.c PriorityQueue.c PriorityQueue.h)
