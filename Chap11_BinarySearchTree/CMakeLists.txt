cmake_minimum_required(VERSION 3.21)
project(Chap11_BinarySearchTree C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap11_BinarySearchTree BinaryTreeTraversal.h BinaryTreeTraversal.c BinarySearchTree.c BinarySearchTree.h BinarySearchTreeMain.c)
