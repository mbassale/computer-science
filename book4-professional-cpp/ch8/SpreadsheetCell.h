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
    enum class Color {
        Black = 1, Red, Green, Blue, Yellow
    };

    SpreadsheetCell() = default;

    SpreadsheetCell(const SpreadsheetCell& other) = default;

    explicit SpreadsheetCell(double value)
            :value{value} { }

    explicit SpreadsheetCell(std::string_view str_value);

    SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

    SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);

    void set(double new_value);

    void set(int new_value) = delete;

    void set(std::string_view new_string);

    [[nodiscard]] double get_value() const;

    [[nodiscard]] std::string get_string() const;

    void set_color(Color new_color);

    [[nodiscard]] Color get_color() const;

    SpreadsheetCell add(const SpreadsheetCell& cell) const;

private:
    double value{};
    mutable size_t num_accesses = 0;
    Color color = Color::Black;

    [[nodiscard]] static std::string double_to_string(double double_value);

    [[nodiscard]] static double string_to_double(std::string_view str_value);

    friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, std::string_view str_value);
};

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator+(const SpreadsheetCell& lhs, double double_value);
SpreadsheetCell operator+(const SpreadsheetCell& lhs, std::string_view str_value);

std::ostream& operator<<(std::ostream& out, const SpreadsheetCell& cell);

#endif //BOOK4_PROFESSIONAL_CPP_SPREADSHEETCELL_H
