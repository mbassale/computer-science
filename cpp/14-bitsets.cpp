#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <bitset>

TEST_CASE("std::bitset supports integer initialization") {
    std::bitset<4> bs(0b0101);
    auto s = bs.to_string();
    REQUIRE(bs[0]); // Reverse order, from least significant to more more significant bit
    REQUIRE_FALSE(bs[1]);
    REQUIRE(bs[2]);
    REQUIRE_FALSE(bs[3]);
}

TEST_CASE("std::bitset supports string initialization") {
    std::bitset<4> bs1(0b0110);
    std::bitset<4> bs2("0110");
    REQUIRE(bs1 == bs2);
}
