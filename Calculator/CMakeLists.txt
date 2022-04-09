cmake_minimum_required(VERSION 3.21)
project(Calculator C)

set(CMAKE_C_STANDARD 99)

add_executable(Calculator InfixToPostfixMain.c ListBaseStack.c ListBaseStack.h InfixToPostfix.c InfixToPostfix.h)
