//
// Created by Marco Bassaletti on 04-03-21.
//
#include <cstdlib>
#include <iostream>
#include <string>


int main() {
    std::string command{ "ping -c 4 google.com" };
    const auto result = std::system(command.c_str());
    std::cout << "The command \'" << command << "\' returned " << result << std::endl;
    return 0;
}
