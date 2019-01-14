cmake_minimum_required(VERSION 3.12)
project(linal_spaceship_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test
    source/Main.cpp
    source/Tests.cpp
    ../../main/source/math/Matrix.cpp)