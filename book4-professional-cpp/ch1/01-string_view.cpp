//
// Created by Marco Bassaletti on 13-03-21.
//

#include "../catch.hpp"
#include <string>

using namespace std;

string_view extractExtension(string_view filename) {
    auto sep = filename.find_last_of('.');
    if (sep != string::npos) {
        return filename.substr(filename.find_last_of('.') + 1);
    }
    return "";
}

TEST_CASE("string view as function parameter")
{
    REQUIRE(extractExtension("") == "");
    REQUIRE(extractExtension("README") == "");
    REQUIRE(extractExtension("c:\\temp\\myfilename.txt") == "txt");
    REQUIRE(extractExtension("/usr/src/linux/README.md") == "md");
}
