cmake_minimum_required(VERSION 3.21)
project(Deque C)

set(CMAKE_C_STANDARD 99)

add_executable(Deque DequeMain.c Deque.c Deque.h)
