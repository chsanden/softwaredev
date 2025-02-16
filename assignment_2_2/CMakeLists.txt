cmake_minimum_required(VERSION 3.29)
project(assignment_2_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment_2_2 main.cpp
        student.h
)

find_package(RapidJSON REQUIRED)
target_include_directories(assignment_2_2 PRIVATE ${RAPIDJSON_INCLUDE_DIRS})