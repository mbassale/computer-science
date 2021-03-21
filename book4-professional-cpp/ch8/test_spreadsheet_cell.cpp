//
// Created by Marco Bassaletti on 20-03-21.
//
#include "../catch.hpp"
#include <sstream>
#include "SpreadsheetCell.h"

TEST_CASE("SpreadsheetCell - construct", "[chapter8]") {
    REQUIRE_NOTHROW(SpreadsheetCell{});
}

TEST_CASE("SpreadsheetCell - string value", "[chapter8]") {
    SpreadsheetCell spreadsheet_cell;
    spreadsheet_cell.set_string("60.0");
    REQUIRE(spreadsheet_cell.get_value() == Approx(60));
}

TEST_CASE("SpreadsheetCell - ostream printing", "[chapter8]") {
    SpreadsheetCell spreadsheet_cell;
    spreadsheet_cell.set_value(60);
    std::ostringstream ss;
    ss << spreadsheet_cell;
    REQUIRE(ss.str() == "60.000000");
}

TEST_CASE("SpreadsheetCell - copy", "[chapter8]") {
    SpreadsheetCell spreadsheetCell1{10};
    SpreadsheetCell spreadsheetCell2{spreadsheetCell1};
    REQUIRE(spreadsheetCell1.get_value() == spreadsheetCell2.get_value());
}

TEST_CASE("SpreadsheetCell - assignment", "[chapter8]") {
    SpreadsheetCell spreadsheetCell1{ 10 };
    SpreadsheetCell spreadsheetCell2;
    spreadsheetCell2 = spreadsheetCell1;
    REQUIRE(spreadsheetCell1.get_value() == spreadsheetCell2.get_value());
}
