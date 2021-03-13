//
// Created by Marco Bassaletti on 13-03-21.
//
#include <string>
#include <iostream>
#include <algorithm>
#include "../../catch.hpp"

using namespace std;

int8_t char_to_digit(char char_digit) {
    return char_digit - '0';
}

char digit_to_char(int8_t digit) {
    return (char)('0' + digit);
}

/**
 * Basic string addition of arbitrary large positive integers using strings and reverse iterators.
 * @param number1
 * @param number2
 * @return New string with the sum of number1 and number2.
 */
std::string basic_string_addition(const std::string& number1, const std::string& number2)
{
    auto it1 = number1.rbegin();
    auto it2 = number2.rbegin();
    string result;
    result.reserve(std::max(number1.size(), number2.size()) + 1);
    uint8_t carry = 0;

    while (it1 != number1.rend() && it2 != number2.rend()) {
        auto digit1 = char_to_digit(*it1);
        auto digit2 = char_to_digit(*it2);
        uint8_t digit_result = digit1 + digit2 + carry;
        char char_digit = digit_to_char(digit_result % 10);
        carry = digit_result / 10;
        result.push_back(char_digit);
        it1++;
        it2++;
    }

    auto copy_with_carry = [&result, &carry](auto it, auto it_end) {
        while (it != it_end) {
            auto digit2 = char_to_digit(*it);
            uint8_t digit_result = digit2 + carry;
            carry = digit_result / 10;
            char char_result = digit_to_char(digit_result % 10);
            result.push_back(char_result);
            it++;
        }
    };

    copy_with_carry(it1, number1.rend());
    copy_with_carry(it2, number2.rend());
    if (carry) {
        result.push_back(digit_to_char(carry));
    }
    std::reverse(result.begin(), result.end());

    return result;
}

/**
 * Basic string multiplication of arbitrary large positive integers using strings and reverse iterators.
 * @param number1
 * @param number2
 * @return New string with the multiplication of number1 and number2.
 */
std::string basic_string_multiplication(const std::string& number1, const std::string& number2) {
    string result;

    int padding = 0;
    auto it1 = number1.rbegin();
    while (it1 != number1.rend()) {
        auto digit1 = char_to_digit(*it1);
        string partial_result;
        uint8_t carry = 0;
        auto it2 = number2.rbegin();
        while (it2 != number2.rend()) {
            auto digit2 = char_to_digit(*it2);
            auto digit_result = digit1 * digit2 + carry;
            partial_result.push_back(digit_to_char(digit_result % 10));
            carry = digit_result / 10;
            it2++;
        }
        if (carry > 0) {
            partial_result.push_back(digit_to_char(carry));
        }
        std::reverse(partial_result.begin(), partial_result.end());
        for (auto i = 0; i < padding; i++) {
            partial_result.push_back('0');
        }
        result = basic_string_addition(result, partial_result);
        padding++;
        it1++;
    }

    return result;
}

TEST_CASE("string addition")
{
    REQUIRE(basic_string_addition("0", "0") == "0");
    REQUIRE(basic_string_addition("1", "1") == "2");
    REQUIRE(basic_string_addition("9", "9") == "18");
    REQUIRE(basic_string_addition("999999999", "1") == "1000000000");
    REQUIRE(basic_string_addition("123456789", "123456789") == "246913578");
}

TEST_CASE("integer multiplication")
{
    REQUIRE(basic_string_multiplication("12", "6") == "72");
    REQUIRE(basic_string_multiplication("123", "123") == "15129");
    REQUIRE(basic_string_multiplication("1000", "1000") == "1000000");
    REQUIRE(basic_string_multiplication("1234567890", "1234567890") == "1524157875019052100");
}
