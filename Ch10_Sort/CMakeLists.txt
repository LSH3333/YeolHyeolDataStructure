cmake_minimum_required(VERSION 3.21)
project(Ch10_Sort C)

set(CMAKE_C_STANDARD 99)

add_executable(Ch10_Sort BubbleSort.c SelectionSort.c)
