cmake_minimum_required(VERSION 3.21)
project(Chap14_kruskal C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap14_kruskal KruskalMain.c ALEdge.h ALGraphKruskal.h ALGraphKruskal.c ArrayBaseStack.c ArrayBaseStack.h
        DLinkedList.c DLinkedList.h PriorityQueue.c PriorityQueue.h UsefulHeap.c UsefulHeap.h)
