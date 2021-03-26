//
// Created by Marco Bassaletti on 20-03-21.
//

#include "SpreadsheetCell.h"

SpreadsheetCell::SpreadsheetCell(std::string_view str_value)
{
    set(str_value);
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
    if (this == &rhs) return *this;
    value = rhs.value;
    return *this;
}

void SpreadsheetCell::set(double new_value)
{
    value = new_value;
}

void SpreadsheetCell::set(std::string_view new_string)
{
    value = string_to_double(new_string);
}

double SpreadsheetCell::get_value() const
{
    num_accesses++;
    return value;
}

std::string SpreadsheetCell::get_string() const
{
    num_accesses++;
    return double_to_string(value);
}

std::string SpreadsheetCell::double_to_string(double double_value)
{
    return std::to_string(double_value);
}

double SpreadsheetCell::string_to_double(std::string_view str_value)
{
    return std::strtod(str_value.data(), nullptr);
}

SpreadsheetCell::Color SpreadsheetCell::get_color() const
{
    return color;
}

void SpreadsheetCell::set_color(SpreadsheetCell::Color new_color)
{
    color = new_color;
}

SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell& cell) const
{
    return SpreadsheetCell(get_value() + cell.get_value());
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
    set(get_value() + rhs.get_value());
    return *this;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
    auto result(lhs);
    result += rhs;
    return result;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, double double_value)
{
    return SpreadsheetCell(lhs.get_value() + double_value);
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, std::string_view str_value)
{
    return SpreadsheetCell(lhs.get_value() + SpreadsheetCell::string_to_double(str_value));
}

std::ostream& operator<<(std::ostream& out, const SpreadsheetCell& cell)
{
    out << cell.get_string();
    return out;
}
