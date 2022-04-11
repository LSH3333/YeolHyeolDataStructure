cmake_minimum_required(VERSION 3.21)
project(Chap07_DequebaseQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap07_DequebaseQueue main.c DequeBaseQueue.c DequeBaseQueue.h Deque.h Deque.c)
