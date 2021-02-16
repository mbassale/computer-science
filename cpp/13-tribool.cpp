#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <boost/logic/tribool.hpp>

using boost::logic::indeterminate;
boost::logic::tribool t = true, f = false, i = indeterminate;

TEST_CASE("Boost tribool converts to bool") {
    REQUIRE(t);
    REQUIRE_FALSE(f);
    REQUIRE(!f);
    REQUIRE_FALSE(!t);
    REQUIRE(indeterminate(i));
    REQUIRE_FALSE(indeterminate(t));
}

TEST_CASE("Boost Tribool supports Boolean oopeartions") {
    auto t_or_f = t || f;
    REQUIRE(t_or_f);
    REQUIRE(indeterminate(t && i));
    REQUIRE(indeterminate(f || i));
    REQUIRE(indeterminate(!i));
}

TEST_CASE("Boost Tribool works nicely with if statements") {
    if (i) FAIL("Indeterminate is true.");
    else if (!i) FAIL("Indeterminate is false.");
    else {} // OK, indeterminate
}