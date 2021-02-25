#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Returns true if predicate is true for *all* elements. Otherwise, returns false.
 * Running time: O(n)
 */
TEST_CASE("all_of") {
    vector<string> words{ "Auntie", "Anne's", "alligator" };
    const auto starts_with_a = [](const auto& word) {
        if (word.empty()) return false;
        return word[0] == 'A' || word[0] == 'a';
    };
    REQUIRE(all_of(words.cbegin(), words.cend(), starts_with_a));
    const auto has_length_six = [](const auto& word) {
        return word.length() == 6;
    };
    REQUIRE_FALSE(all_of(words.cbegin(), words.cend(), has_length_six));
}

/**
 * Returns true if predicate is true for *any* element. Otherwise, returns false.
 * Running time: O(n)
 */
TEST_CASE("any_of") {
    vector<string> words{ "Barber", "baby", "bubbles" };
    const auto contains_bar = [](const auto& word) {
        return word.find("Bar") != string::npos;
    };
    REQUIRE(any_of(words.cbegin(), words.cend(), contains_bar));
    const auto is_empty = [](const auto& word) { return word.empty(); };
    REQUIRE_FALSE(any_of(words.cbegin(), words.cend(), is_empty));
}

/**
 * Returns true if predicate is true for *no* element. Otherwise, returns false.
 * Running time: O(n)
 */
TEST_CASE("none_of") {
    vector<string> words{ "Camel", "on", "the", "ceiling" };
    const auto is_hump_day = [](const auto& word) {
        return word == "hump day";
    };
    REQUIRE(none_of(words.cbegin(), words.cend(), is_hump_day));
    const auto is_definite_article = [](const auto& word) {
        return word == "the" || word == "ye";
    };
    REQUIRE_FALSE(none_of(words.cbegin(), words.cend(), is_definite_article));
}

/**
 * For each algorithm with begin and end iterators.
 * Running time: O(n)
 */
TEST_CASE("for_each") {
    vector<string> words{ "David", "Donald", "Doo" };
    size_t number_of_Ds{};
    const auto count_Ds = [&number_of_Ds](const auto& word) {
        if (word.empty()) return;
        if (word[0] == 'D') ++number_of_Ds;
    };
    for_each(words.cbegin(), words.cend(), count_Ds);
    REQUIRE(3 == number_of_Ds);
}

/**
 * For each algorithm with begin iterator and a number of elements to process.
 * Running time: O(n)
 */
TEST_CASE("for_each_n") {
    vector<string> words{ "ear", "egg", "elephant" };
    size_t characters{};
    const auto count_characters = [&characters](const auto& word) {
        characters += word.size();
    };
    for_each_n(words.cbegin(), words.size(), count_characters);
    REQUIRE(14 == characters);
}

/**
 * Find first element in a sequence matching some user-defined criteria.
 * Running time: O(n)
 */
TEST_CASE("find, find_if, find_if_not") {
    vector<string> words{ "fiffer", "feffer", "feff" };

    const auto find_result = find(words.cbegin(), words.cend(), "feff");
    REQUIRE(*find_result == words.back());

    const auto  defends_digital_privacy = [](const auto& word) {
        return word.find("eff") != string::npos;
    };
    const auto find_if_result = find_if(words.cbegin(), words.cend(), defends_digital_privacy);
    REQUIRE(*find_if_result == "feffer");

    const auto find_if_not_result = find_if_not(words.cbegin(), words.cend(), defends_digital_privacy);
    REQUIRE(*find_if_not_result == words.front());
}

/**
 * Find last occurrence of subsequence.
 * Running time: O(n^2)
 */
TEST_CASE("find_end") {
    vector<string> words1{ "Goat", "girl", "googoo", "googles" };
    vector<string> words2{ "girl", "googoo" };
    const auto find_end_result1 = find_end(words1.cbegin(), words1.cend(), words2.cbegin(), words2.cend());
    REQUIRE(*find_end_result1 == words1[1]);

    const auto has_length = [](const auto& word, const auto& len) {
        return word.length() == len;
    };
    vector<size_t> sizes{ 4, 6 };
    const auto find_end_result2 = find_end(words1.cbegin(), words1.cend(), sizes.cbegin(), sizes.cend(), has_length);
    REQUIRE(*find_end_result2 == words1[1]);
}

/**
 * Find first occurrence in sequence 1 equal to some element in sequence 2.
 * Running time: O(n^2)
 */
TEST_CASE("find_first_of") {
    vector<string> words{ "Hen", "in", "a", "hat" };
    vector<string> indefinite_articles{ "a", "an" };
    const auto find_first_of_result = find_first_of(words.cbegin(), words.cend(),
                                                    indefinite_articles.cbegin(), indefinite_articles.cend());
    REQUIRE(*find_first_of_result == words[2]);
}
