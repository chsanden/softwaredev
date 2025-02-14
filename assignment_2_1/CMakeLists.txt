cmake_minimum_required(VERSION 3.29)
project(assignment_2_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment_2_1 main.cpp
        func.h)

find_path(RAPIDCSV_INCLUDE "rapidcsv.h")
target_include_directories(assignment_2_1 PRIVATE ${RAPIDCSV_INCLUDE})
