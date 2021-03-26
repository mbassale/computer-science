cmake_minimum_required(VERSION 3.17)
project(book4_professional_cpp)

set(CMAKE_CXX_STANDARD 17)

SET(SOURCES
        main.cpp
        ch1/01-string_view.cpp
        ch7/01-new-delete.cpp
        ch7/02-smart-pointers.cpp
        ch8/SpreadsheetCell.cpp
        ch8/SpreadsheetCell.h
        ch8/test_spreadsheet_cell.cpp
        ch9/01-friend.cpp
        ch9/02-spreadsheet.cpp
        ch9/Spreadsheet.cpp ch9/Spreadsheet.h
        ch9/SpreadsheetApplication.cpp ch9/SpreadsheetApplication.h)

add_executable(book4_professional_cpp ${SOURCES})
