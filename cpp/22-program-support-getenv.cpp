//
// Created by Marco Bassaletti on 04-03-21.
//
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    std::string variable_name{ "PATH" };
    std::string result{ std::getenv(variable_name.c_str()) };
    std::cout << "The variable " << variable_name << " equals " << result << std::endl;
    return 0;
}
