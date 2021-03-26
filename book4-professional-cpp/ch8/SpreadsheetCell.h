//
// Created by Marco Bassaletti on 20-03-21.
//

#ifndef BOOK4_PROFESSIONAL_CPP_SPREADSHEETCELL_H
#define BOOK4_PROFESSIONAL_CPP_SPREADSHEETCELL_H

#include <string>
#include <string_view>
#include <ostream>

class SpreadsheetCell {
public:
    SpreadsheetCell() = default;

    SpreadsheetCell(const SpreadsheetCell& other) = default;

    explicit SpreadsheetCell(double value)
            :value{value} { }

    explicit SpreadsheetCell(std::string_view str_value);

    SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

    void set(double new_value);

    void set(std::string_view new_string);

    [[nodiscard]] double get_value() const;

    [[nodiscard]] std::string get_string() const;

private:
    double value{};
    mutable size_t num_accesses = 0;

    [[nodiscard]] static std::string double_to_string(double double_value);

    [[nodiscard]] static double string_to_double(std::string_view str_value);
};

std::ostream& operator<<(std::ostream& out, const SpreadsheetCell& cell);

#endif //BOOK4_PROFESSIONAL_CPP_SPREADSHEETCELL_H
