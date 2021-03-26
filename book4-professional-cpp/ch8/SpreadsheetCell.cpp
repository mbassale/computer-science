//
// Created by Marco Bassaletti on 20-03-21.
//

#include "SpreadsheetCell.h"

SpreadsheetCell::SpreadsheetCell(std::string_view str_value) {
    set_string(str_value);
}

SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &rhs) {
    if (this == &rhs) return *this;
    value = rhs.value;
    return *this;
}

void SpreadsheetCell::set_value(double new_value) {
    value = new_value;
}

double SpreadsheetCell::get_value() const {
    num_accesses++;
    return value;
}

void SpreadsheetCell::set_string(std::string_view new_string) {
    num_accesses++;
    value = string_to_double(new_string);
}

std::string SpreadsheetCell::get_string() const {
    return double_to_string(value);
}

std::string SpreadsheetCell::double_to_string(double double_value) {
    return std::to_string(double_value);
}

double SpreadsheetCell::string_to_double(std::string_view str_value) {
    return std::strtod(str_value.data(), nullptr);
}

std::ostream &operator<<(std::ostream &out, const SpreadsheetCell &cell) {
    out << cell.get_string();
    return out;
}
