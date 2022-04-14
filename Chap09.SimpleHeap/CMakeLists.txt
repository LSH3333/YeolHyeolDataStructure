cmake_minimum_required(VERSION 3.21)
project(Chap09_SimpleHeap C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap09_SimpleHeap SimpleHeapMain.c SimpleHeap.c SimpleHeap.h)
