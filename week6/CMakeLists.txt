cmake_minimum_required(VERSION 3.12)
project(week6 C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS -pthread)

add_executable(week6 ex6.c)