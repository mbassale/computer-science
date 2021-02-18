#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stack>

TEST_CASE("std::stack supports push/pop/top operations") {
    std::vector<int> vec{ 1, 3 };
    std::stack<int, decltype(vec)> easy_as(vec);
    REQUIRE(easy_as.top() == 3);
    easy_as.pop(); // 3
    easy_as.push(2); // 1, 2
    REQUIRE(easy_as.top() == 2);
}
