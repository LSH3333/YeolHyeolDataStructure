cmake_minimum_required(VERSION 3.21)
project(Chap08_ExpTree C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap08_ExpTree main.c BinaryTreeTraversal.c BinaryTreeTraversal.h ListBaseStack.h ListBaseStack.c ExpressionTree.c ExpressionTree.h)
