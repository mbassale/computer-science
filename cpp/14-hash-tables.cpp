#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <functional>
#include <unordered_set>

TEST_CASE("std::hash<long> returns") {
    std::hash<long> hasher;
    auto hash_code_42 = hasher(42);
    SECTION("equal hash codes for equal keys") {
        REQUIRE(hash_code_42 == hasher(42));
    }
    SECTION("unequal hash codes for unequal keys") {
        REQUIRE(hash_code_42 != hasher(43));
    }
}

TEST_CASE("std::equal_to<long> returns") {
    std::equal_to<long> long_equal_to;
    SECTION("true when arguments equal") {
        REQUIRE(long_equal_to(42, 42));
    }
    SECTION("false when arguments unequal") {
        REQUIRE_FALSE(long_equal_to(42, 43));
    }
}

TEST_CASE("std::unordered_set") {
    std::unordered_set<unsigned long> sheep(100);
    SECTION("allows bucket count specification on construction") {
        REQUIRE(sheep.bucket_count() >= 100);
        REQUIRE(sheep.bucket_count() <= sheep.max_bucket_count());
        REQUIRE(sheep.max_load_factor() == Approx(1.0));
    }
    SECTION("allows us to reserve space for elements") {
        sheep.reserve(100'000);
        sheep.insert(0);
        REQUIRE(sheep.load_factor() <= 0.00001);
        while (sheep.size() < 100'000) {
            sheep.insert(sheep.size());
        }
        REQUIRE(sheep.load_factor() <= 1.0);
    }
}