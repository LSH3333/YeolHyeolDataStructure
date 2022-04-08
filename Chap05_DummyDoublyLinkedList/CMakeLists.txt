cmake_minimum_required(VERSION 3.21)
project(Chap05_DummyDoublyLinkedList C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap05_DummyDoublyLinkedList main.c DummyDoublyLinkedList.c DummyDoublyLinkedList.h)
