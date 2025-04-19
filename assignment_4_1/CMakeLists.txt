cmake_minimum_required(VERSION 3.31)

IF (WIN32)
    set(VCPKG_TARGET_TRIPLET "x64-mingw-static" CACHE STRING "VCPKG Triplet")
ENDIF ()

project(assignment_4_1)




set(CMAKE_CXX_STANDARD 20)

add_executable(assignment_4_1 main.cpp)
find_package(SQLiteCpp CONFIG REQUIRED)
target_link_libraries(assignment_4_1 PRIVATE SQLiteCpp)