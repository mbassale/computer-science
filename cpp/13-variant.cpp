#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <variant>

struct EscapeCapsule {
    EscapeCapsule(int x) : weight_kg{ x } {}
    int weight_kg;
};

struct BugblatterBeast {
    BugblatterBeast() : is_ravenous{ true }, weight_kg{ 20000 } {}
    bool is_ravenous;
    int weight_kg;
};

TEST_CASE("std::variant") {
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    REQUIRE(hagunemnon.index() == 0);

    hagunemnon.emplace<EscapeCapsule>(600);
    REQUIRE(hagunemnon.index() == 1);

    REQUIRE(std::get<EscapeCapsule>(hagunemnon).weight_kg == 600);
    REQUIRE(std::get<1>(hagunemnon).weight_kg == 600);
    REQUIRE_THROWS_AS(std::get<0>(hagunemnon), std::bad_variant_access);
}

TEST_CASE("std::variant 2") {
    std::variant<BugblatterBeast, EscapeCapsule> hagunemnon;
    hagunemnon.emplace<EscapeCapsule>(600);
    auto lbs = std::visit([](auto& x) { return 2.2*x.weight_kg; }, hagunemnon);
    REQUIRE(lbs == 1320);
}