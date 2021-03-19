cmake_minimum_required(VERSION 3.17)
project(book4_professional_cpp)

set(CMAKE_CXX_STANDARD 17)

SET(SOURCES
        main.cpp
        ch1/01-string_view.cpp
        ch7/01-new-delete.cpp
        ch7/02-smart-pointers.cpp)

add_executable(book4_professional_cpp ${SOURCES})
