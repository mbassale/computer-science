cmake_minimum_required(VERSION 3.17)
project(book3_algorithms_illuminated)

set(CMAKE_CXX_STANDARD 17)

SET(SOURCES
        main.cpp part1/ch1/01_integer_multiplication.cpp)

add_executable(book3_algorithms_illuminated ${SOURCES})
