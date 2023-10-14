cmake_minimum_required(VERSION 3.24)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Code
        CFG.cpp
        CFG.h
        main.cpp)
