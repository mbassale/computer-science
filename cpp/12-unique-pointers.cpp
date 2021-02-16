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

TEST_CASE("UniquePtr can be used in move") {
    auto aragon = std::make_unique<DeadMenOfDunharrow>();
    SECTION("construction") {
        auto son_of_arathorn{ std::move(aragon) };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment") {
        auto son_of_arathorn = std::make_unique<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = std::move(aragon);
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
}

TEST_CASE("UniquePtr to array supports operator[]") {
    std::unique_ptr<int[]> squares {
        new int[] { 1, 4, 9, 16, 25 }
    };
    squares[0] = 1;
    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}

TEST_CASE("UniquePtr deleter") {
    auto my_deleter = [](int* x) {
        printf("Deleting an int at %p.\n", x);
        delete x;
    };
    SECTION("custom deleter execution") {
        std::unique_ptr<int, decltype(my_deleter)> my_int {
            new int,
            my_deleter
        };
    }
}