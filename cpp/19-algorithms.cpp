#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
#include <map>
#include <random>
#include <algorithm>
#include <boost/algorithm/string/case_conv.hpp>


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

/**
 * Find adjacent elements that are equal or match predicate. Returns the first repeat.
 * Running time: O(n)
 */
TEST_CASE("adjacent_find") {
    vector<string> words{ "Icabod", "is", "itchy" };
    const auto first_letters_match = [](const auto& word1, const auto& word2) {
        if (word1.empty() || word2.empty()) return false;
        return word1.front() == word2.front();
    };
    const auto adjacent_find_result = adjacent_find(words.cbegin(), words.cend(), first_letters_match);
    REQUIRE(*adjacent_find_result == words[1]);
}

/**
 * Count elements that match some criteria.
 * Running time: O(n)
 */
TEST_CASE("count") {
    vector<string> words{ "jelly", "jar", "and", "jam" };
    const auto n_ands = count(words.cbegin(), words.cend(), "and");
    REQUIRE(n_ands == 1);

    const auto contains_a = [](const auto& word) {
        return word.find('a') != string::npos;
    };
    const auto count_if_result = count_if(words.cbegin(), words.cend(), contains_a);
    REQUIRE(count_if_result == 3);
}

/**
 * Find the first mismatch between two sequences.
 * Running time: O(n)
 */
TEST_CASE("mismatch") {
    vector<string> words1{ "Kitten", "Kangaroo", "Kick" };
    vector<string> words2{ "Kitten", "bandicoot", "roundhouse" };
    const auto mismatch_result1 = mismatch(words1.cbegin(), words1.cend(), words2.cbegin());
    REQUIRE(*mismatch_result1.first == "Kangaroo");
    REQUIRE(*mismatch_result1.second == "bandicoot");

    const auto second_letter_matches = [](const auto& word1, const auto& word2) {
        if (word1.size() < 2 || word2.size() < 2) return false;
        return word1[1] == word2[1];
    };
    const auto mismatch_result2 = mismatch(words1.cbegin(), words1.cend(), words2.cbegin(), second_letter_matches);
    REQUIRE(*mismatch_result2.first == "Kick");
    REQUIRE(*mismatch_result2.second == "roundhouse");
}

/**
 * Determines if two sequences are equal.
 * Running time: O(n)
 */
TEST_CASE("equal") {
    vector<string> words1{ "Lazy", "lion", "licks" };
    vector<string> words2{ "Lazy", "lion", "kicks" };
    const auto equal_result1 = equal(words1.cbegin(), words1.cend(), words2.cbegin());
    REQUIRE_FALSE(equal_result1);

    words2[2] = words1[2];
    const auto equal_result2 = equal(words1.cbegin(), words1.cend(), words2.cbegin());
    REQUIRE(equal_result2);
}

/**
 * Determines if elements of two sequences are equal, but in different order.
 * Running time: O(n^2)
 */
TEST_CASE("is_permutation") {
    vector<string> words1{ "moonlight", "mighty", "nice" };
    vector<string> words2{ "nice", "moonlight", "mighty" };
    const auto result = is_permutation(words1.cbegin(), words1.cend(), words2.cbegin());
    REQUIRE(result);
}

/**
 * Locates a subsequence, returns an iterator pointing to the first element of the first sequence.
 * Running time: O(n^2)
 */
TEST_CASE("search") {
    vector<string> words1{ "Nine", "new", "neckties", "and", "a", "nightshirt" };
    vector<string> words2{ "and", "a", "nightshirt" };
    const auto search_result_1 = search(words1.cbegin(), words1.cend(), words2.cbegin(), words2.cend());
    REQUIRE(*search_result_1 == "and");

    vector<string> words3{ "and", "a", "nightpant" };
    const auto search_result_2 = search(words1.cbegin(), words1.cend(), words3.cbegin(), words3.cend());
    REQUIRE(search_result_2 == words1.cend());
}

/**
 * Locates a subsequence, containing identical, consecutive values.
 * Running time: O(n)
 */
TEST_CASE("search_n") {
    vector<string> words{ "an", "orange", "owl", "owl", "owl", "today" };
    const auto result = search_n(words.cbegin(), words.cend(), 3, "owl");
    REQUIRE(result == words.cbegin() + 2);
}

/**
 * Copy a sequence into other.
 * Running time: O(n)
 */
TEST_CASE("copy") {
    vector<string> words1{ "and", "prosper" };
    vector<string> words2{ "Live", "long" };
    copy(words1.cbegin(), words1.cend(), back_inserter(words2));
    REQUIRE(words2 == vector<string>{ "Live", "long", "and", "prosper" });
}

/**
 * Copy a sequence into other upto n elements.
 * Running time: O(n)
 */
TEST_CASE("copy_n") {
    vector<string> words1{ "on", "the", "wind" };
    vector<string> words2{ "I'm", "a", "leaf" };
    copy_n(words1.cbegin(), words1.size(), back_inserter(words2));
    REQUIRE(words2 == vector<string>{ "I'm", "a", "leaf", "on", "the", "wind" });
}

/**
 * Copy the reverse of one sequence into another.
 * Running time: O(n)
 */
TEST_CASE("copy_backward") {
    vector<string> words1{ "A", "man", "a", "plan", "a", "bran", "muffin" };
    vector<string> words2{ "a", "canal", "Panama" };
    const auto result = copy_backward(words2.cbegin(), words2.cend(), words1.end());
    REQUIRE(words1 == vector<string>{ "A", "man", "a", "plan", "a", "canal", "Panama" });
}

struct MoveDetector {
    MoveDetector() : owner{ true } {}
    MoveDetector(const MoveDetector&) = delete;
    MoveDetector& operator=(const MoveDetector&) = delete;
    MoveDetector(MoveDetector&& o) = delete;
    MoveDetector& operator=(MoveDetector&& o) noexcept {
        o.owner = false;
        owner = true;
        return *this;
    }
    explicit operator bool() const { return owner; }
    bool owner;
};

/**
 * Move elements from first sequence into second sequence. Elements must be moveable.
 * Running time: O(n)
 */
TEST_CASE("move") {
    vector<MoveDetector> detectors1(2);
    vector<MoveDetector> detectors2(2);
    move(detectors1.begin(), detectors1.end(), detectors2.begin());
    REQUIRE_FALSE(detectors1[0]);
    REQUIRE_FALSE(detectors1[1]);
    REQUIRE(detectors2[0]);
    REQUIRE(detectors2[1]);
}

/**
 * Move the reverse of one sequence into another.
 * Running time: O(n)
 */
TEST_CASE("move_backward") {
    vector<MoveDetector> detectors1(2);
    vector<MoveDetector> detectors2(2);
    move_backward(detectors1.begin(), detectors1.end(), detectors2.begin());
    REQUIRE_FALSE(detectors1[0]);
    REQUIRE_FALSE(detectors1[1]);
    REQUIRE(detectors2[0]);
    REQUIRE(detectors2[1]);
}

/**
 * Swap elements from one sequence into another.
 * Running time: O(n)
 */
TEST_CASE("swap_ranges") {
    vector<string> words1{ "The", "king", "is", "dead" };
    vector<string> words2{ "Long", "live", "the", "king." };
    swap_ranges(words1.begin(), words1.end(), words2.begin());
    REQUIRE(words1 == vector<string>{ "Long", "live", "the", "king." });
    REQUIRE(words2 == vector<string>{ "The", "king", "is", "dead" });
}

/**
 * Transforms elements in a sequence according to unary or binary operations.
 * Running time: O(n)
 */
TEST_CASE("transform") {
    vector<string> words1{ "farewell", "hello", "farewell", "hello" };
    vector<string> result1;
    auto upper = [](string x) {
        boost::algorithm::to_upper(x);
        return x;
    };
    transform(words1.begin(), words1.end(), back_inserter(result1), upper);
    REQUIRE(result1 == vector<string>{ "FAREWELL", "HELLO", "FAREWELL", "HELLO" });

    vector<string> words2{ "light", "human", "bro", "quantum" };
    vector<string> words3{ "radar", "robot", "pony", "bit" };
    vector<string> result2;
    auto portmantize = [](const auto &x, const auto &y) {
        const auto x_letters = min(size_t{ 2 }, x.size());
        string result{ x.begin(), x.begin() + x_letters };
        const auto y_letters = min(size_t{3}, y.size());
        result.insert(result.end(), y.end() - y_letters, y.end());
        return result;
    };
    transform(words2.begin(), words2.end(), words3.begin(), back_inserter(result2), portmantize);
    REQUIRE(result2 == vector<string>{ "lidar", "hubot", "brony", "qubit" });
}

/**
 * Replaces certain elements in a sequence with some new element.
 * Running time: O(n)
 */
TEST_CASE("replace") {
    using namespace std::literals;
    vector<string> words1{ "There", "is", "no", "try" };
    replace(words1.begin(), words1.end(), "try"sv, "spoon"sv);
    REQUIRE(words1 == vector<string>{ "There", "is", "no", "spoon" });

    const vector<string> words2{ "There", "is", "no", "spoon" };
    vector<string> words3{ "There", "is", "no", "spoon" };
    auto has_two_os = [](const auto& x) {
        return count(x.begin(), x.end(), 'o') == 2;
    };
    replace_copy_if(words2.begin(), words2.end(), words3.begin(), has_two_os, "try"sv);
    REQUIRE(words3 == vector<string>{ "There", "is", "no", "try" });
}

/**
 * Fills a sequence with some value.
 * Running time: O(n)
 */
TEST_CASE("fill") {
    vector<string> answer1(6);
    fill(answer1.begin(), answer1.end(), "police");
    REQUIRE(answer1 == vector<string>{ "police", "police", "police",
                                       "police", "police", "police" });

    vector<string> answer2;
    fill_n(back_inserter(answer2), 6, "police");
    REQUIRE(answer2 == vector<string>{ "police", "police", "police",
                                       "police", "police", "police" });
}

/**
 * Fills a sequence by invoking a function object.
 * Running time: O(n)
 */
TEST_CASE("generate") {
    auto i{ 1 };
    auto pow_of_2 = [&i]() {
        const auto tmp = i;
        i *= 2;
        return tmp;
    };
    vector<int> series1(6);
    generate(series1.begin(), series1.end(), pow_of_2);
    REQUIRE(series1 == vector<int>{ 1, 2, 4, 8, 16, 32 });

    vector<int> series2;
    generate_n(back_inserter(series2), 6, pow_of_2);
    REQUIRE(series2 == vector<int>{ 64, 128, 256, 512, 1024, 2048 });
}

/**
 * Removes elements from a sequence.
 * Running time: O(n)
 */
TEST_CASE("remove") {
    auto is_vowel = [](char x) {
        const static string vowels{ "aeiouAEIOU" };
        return vowels.find(x) != string::npos;
    };
    string pilgrim = "Among the things Billy Pilgrim could not change "
                     "were the past, the present, and the future.";
    const auto new_end = remove_if(pilgrim.begin(), pilgrim.end(), is_vowel);
    REQUIRE(pilgrim == "mng th thngs Blly Plgrm cld nt chng wr th pst, th prsnt, nd th ftr.present, and the future.");
    pilgrim.erase(new_end, pilgrim.end());
    REQUIRE(pilgrim == "mng th thngs Blly Plgrm cld nt chng wr th pst, th prsnt, nd th ftr.");
}

/**
 * Remove repeated elements. Tests equality or an optional predicate.
 * Running time: O(n)
 */
TEST_CASE("unique") {
    string without_walls = "Wallless";
    const auto new_end = unique(without_walls.begin(), without_walls.end());
    without_walls.erase(new_end, without_walls.end());
    REQUIRE(without_walls == "Wales");
}

/**
 * Reverses the order of a sequence.
 * Running time: O(n)
 */
TEST_CASE("reverse") {
    string stinky = "diaper";
    reverse(stinky.begin(), stinky.end());
    REQUIRE(stinky == "repaid");
}

/**
 * Sample a new sequence from a population with uniform distribution.
 * Running time: O(n)
 */
TEST_CASE("sample") {
    const string population = "ABCD";
    const size_t n_samples{ 1'000'000 };
    mt19937_64 urbg;

    const auto sample_length = [&population, &urbg](size_t n) {
        map<string, size_t> counts;
        for (size_t i{}; i < n_samples; i++) {
            string result;
            sample(population.begin(), population.end(), back_inserter(result), n, urbg);
            counts[result]++;
        }

        for (const auto&[sample, sample_count] : counts) {
            const auto percentage = 100.0 * sample_count / static_cast<double>(n_samples);
            REQUIRE(sample.length() == n);
            REQUIRE(percentage > 0);
        }
    };

    for (auto n = 0; n < 5; n++) {
        sample_length(n);
    }
}

/**
 * Generates a random permutation from a sequence.
 * Running time: O(n)
 */
TEST_CASE("shuffle") {
    const string population = "ABCD";
    const size_t n_samples{ 1'000'000 };
    mt19937_64 urbg;
    map<string, size_t> samples;
    for (size_t i{}; i < n_samples; i++) {
        string result{ population };
        shuffle(result.begin(), result.end(), urbg);
        samples[result]++;
    }
    for (const auto&[sample, n] : samples) {
        const auto percentage = 100.0 * n / n_samples;
        REQUIRE(sample.length() == population.length());
        REQUIRE(percentage > 0);
    }
}