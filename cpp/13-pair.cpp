#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <utility>

struct Socialite { const char* birthname; };
struct Valet { const char* surname; };
Socialite bertie{ "Wilberforce" };
Valet reginald{ "Jeeves" };

TEST_CASE("std::pair permits access to members") {
    std::pair<Socialite, Valet> inimitable_duo{ bertie, reginald };
    REQUIRE(inimitable_duo.first.birthname == bertie.birthname);
    REQUIRE(inimitable_duo.second.surname == reginald.surname);
}

TEST_CASE("std::pair works with structured binding") {
    std::pair<Socialite, Valet> inimitable_duo{ bertie, reginald };
    auto& [idle_rich, butler] = inimitable_duo;
    REQUIRE(idle_rich.birthname == bertie.birthname);
    REQUIRE(butler.surname == reginald.surname);
}