cmake_minimum_required(VERSION 3.21)
project(Chap10_RadixSort C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap10_RadixSort RadixSort.c ListBaseQueue.h ListBaseQueue.c)
