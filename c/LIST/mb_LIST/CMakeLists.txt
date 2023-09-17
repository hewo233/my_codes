cmake_minimum_required(VERSION 3.26)
project(mb_LIST)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mb_LIST
        main.cpp
        SList.cpp
        SList.h)
