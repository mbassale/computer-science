#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <string_view>

TEST_CASE("std::string_view supports") {
    SECTION("default construction") {
        std::string_view view;
        REQUIRE(view.data() == nullptr);
        REQUIRE(view.size() == 0);
        REQUIRE(view.empty());
    }
    SECTION("construction from string") {
        std::string word("sacrosanct");
        std::string_view view(word);
        REQUIRE(view == "sacrosanct");
    }
    SECTION("construction from C-string") {
        auto word = "viewership";
        std::string_view view(word);
        REQUIRE(view == "viewership");
    }
    SECTION("construction from C-string and length") {
        auto word = "viewership";
        std::string_view view(word, 4);
        REQUIRE(view == "view");
    }
}

TEST_CASE("std::string_view is modifiable with") {
    std::string_view view("previewing");
    SECTION("remove_prefix") {
        view.remove_prefix(3);
        REQUIRE(view == "viewing");
    }
    SECTION("remove_suffix") {
        view.remove_suffix(3);
        REQUIRE(view == "preview");
    }
}

size_t count_vees(std::string_view my_view) {
    size_t result{};
    for (auto letter : my_view) {
        if (letter == 'v') result++;
    }
    return result;
}

TEST_CASE("std::string_view as function argument") {
    SECTION("std::string argument") {
        std::string word("venerable and vested");
        REQUIRE(count_vees(word) == 2);
    }
    SECTION("string literal") {
        auto word = "venerable and vested";
        REQUIRE(count_vees(word) == 2);
    }
}
