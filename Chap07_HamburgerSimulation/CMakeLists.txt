cmake_minimum_required(VERSION 3.21)
project(Chap07_HamburgerSimulation C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap07_HamburgerSimulation HamburgerSim.c CircularQueue.h CircularQueue.c)

