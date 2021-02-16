#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <memory>

struct DeadMenOfDunharrow {
    DeadMenOfDunharrow(const char* m="") : message{m} {
        oaths_to_fulfill++;
    }
    ~DeadMenOfDunharrow() {
        oaths_to_fulfill--;
    }
    const char* message;
    static int oaths_to_fulfill;
};

int DeadMenOfDunharrow::oaths_to_fulfill{};
using SharedOathbreakers = std::shared_ptr<DeadMenOfDunharrow>;

TEST_CASE("SharedPtr can be used in copy") {
    auto aragorn = std::make_shared<DeadMenOfDunharrow>();
    SECTION("construction") {
        auto son_of_arathorn{ aragorn };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment") {
        SharedOathbreakers son_of_arathorn;
        son_of_arathorn = aragorn;
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment, and original gets discarded") {
        auto son_of_arathorn = std::make_shared<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = aragorn;
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
}
