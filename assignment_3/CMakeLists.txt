cmake_minimum_required(VERSION 3.29)
project(assignment_3)

IF (WIN32)
    set(VCPKG_TARGET_TRIPLET "x64-mingw-static" CACHE STRING "VCPKG Triplet")
ENDIF ()

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

add_executable(assignment_3 main.cpp)

target_link_libraries(assignment_3 PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)