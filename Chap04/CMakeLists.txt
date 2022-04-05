cmake_minimum_required(VERSION 3.21)
project (Chap04)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chap04 Prob4-1.c Prob4-2.c DLinkedList.c DLinkedList.h DLinkedListMain.c PointListMain.c Point.h Point.c DLinkedListSortMain.c)
