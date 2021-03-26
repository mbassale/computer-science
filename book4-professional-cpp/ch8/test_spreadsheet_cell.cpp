//
// Created by Marco Bassaletti on 20-03-21.
//
#include "../catch.hpp"
#include <sstream>
#include "SpreadsheetCell.h"

TEST_CASE("SpreadsheetCell - construct", "[chapter8]")
{
    REQUIRE_NOTHROW(SpreadsheetCell{});
}

TEST_CASE("SpreadsheetCell - string value", "[chapter8]")
{
    SpreadsheetCell spreadsheet_cell;
    spreadsheet_cell.set("60.0");
    REQUIRE(spreadsheet_cell.get_value() == Approx(60));
}

TEST_CASE("SpreadsheetCell - ostream printing", "[chapter8]")
{
    SpreadsheetCell spreadsheet_cell;
    spreadsheet_cell.set(60.0);
    std::ostringstream ss;
    ss << spreadsheet_cell;
    REQUIRE(ss.str() == "60.000000");
}

TEST_CASE("SpreadsheetCell - copy", "[chapter8]")
{
    SpreadsheetCell spreadsheetCell1{10};
    SpreadsheetCell spreadsheetCell2{spreadsheetCell1};
    REQUIRE(spreadsheetCell1.get_value() == spreadsheetCell2.get_value());
}

TEST_CASE("SpreadsheetCell - assignment", "[chapter8]")
{
    SpreadsheetCell spreadsheetCell1{10};
    SpreadsheetCell spreadsheetCell2;
    spreadsheetCell2 = spreadsheetCell1;
    REQUIRE(spreadsheetCell1.get_value() == spreadsheetCell2.get_value());
}

TEST_CASE("SpreadsheetCell - color getter/setter", "[chapter 9]")
{
    SpreadsheetCell spreadsheet_cell;
    REQUIRE(spreadsheet_cell.get_color() == SpreadsheetCell::Color::Black);
    spreadsheet_cell.set_color(SpreadsheetCell::Color::Yellow);
    REQUIRE(spreadsheet_cell.get_color() == SpreadsheetCell::Color::Yellow);
}

TEST_CASE("SpreadsheetCell - adding", "[chapter 9]")
{
    SpreadsheetCell cell1{4}, cell2{5};
    SpreadsheetCell cell3 = cell1.add(cell2);
    REQUIRE(cell3.get_value() == Approx(9));
    SpreadsheetCell cell4 = cell1 + cell2;
    REQUIRE(cell4.get_value() == Approx(9));
    SpreadsheetCell cell5 = cell1 + 25;
    REQUIRE(cell5.get_value() == Approx(29));
    SpreadsheetCell cell6 = cell1 + "25";
    REQUIRE(cell6.get_value() == Approx(29));
}
