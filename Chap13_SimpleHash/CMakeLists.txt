cmake_minimum_required(VERSION 3.21)
project(Chap13_SimpleHash C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap13_SimpleHash main.c Person.c Person.h Slot.h Table.c Table.h)
