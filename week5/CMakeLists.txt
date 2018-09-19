cmake_minimum_required(VERSION 3.12)
project(week5 C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS -pthread)

add_executable(week5 ex3.c)