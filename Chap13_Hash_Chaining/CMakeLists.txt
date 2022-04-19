cmake_minimum_required(VERSION 3.21)
project(Chap13_Hash_Chaining C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap13_Hash_Chaining ChangedTableMain.c DLinkedList.h DLinkedList.c Person.c Person.h Slot.h Table.h Table.c)
