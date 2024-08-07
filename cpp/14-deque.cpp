#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <deque>

TEST_CASE("std::deque supports front insertion") {
    std::deque<char> deckard;
    deckard.push_front('a');
    deckard.push_back('i');
    deckard.push_front('c');
    deckard.push_back('n');
    REQUIRE(deckard[0] == 'c');
    REQUIRE(deckard[1] == 'a');
    REQUIRE(deckard[2] == 'i');
    REQUIRE(deckard[3] == 'n');
}
