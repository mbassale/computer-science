//
// Created by Marco Bassaletti on 02-03-21.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <set>
#include <chrono>
#include <future>
#include <mutex>
#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <vector>

using namespace std;

struct Stopwatch {
    Stopwatch(std::chrono::nanoseconds& result) : result{ result }, start{ std::chrono::high_resolution_clock::now() } {}
    ~Stopwatch() {
        result = std::chrono::high_resolution_clock::now() - start;
    }
private:
    std::chrono::nanoseconds& result;
    const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

TEST_CASE("async returns valid future") {
    using namespace std::string_literals;
    auto the_future = async([]{ return "female"s; });
    REQUIRE(the_future.valid());
}

TEST_CASE("future invalid by default") {
    future<bool> default_future;
    REQUIRE_FALSE(default_future.valid());
}

TEST_CASE("async returns the return value of the function object") {
    using namespace std::string_literals;
    auto the_future = async([]{ return "female"s; });
    REQUIRE(the_future.get() == "female");
}

TEST_CASE("get may throw") {
    auto ghostrider = async([]{ throw runtime_error{ "The pattern is full." }; });
    REQUIRE_THROWS_AS(ghostrider.get(), runtime_error);
}

TEST_CASE("wait_for indicates whether a task is ready") {
    using namespace std::chrono_literals;
    auto sleepy = async(launch::async, []{ this_thread::sleep_for(100ms); });
    const auto not_ready_yet = sleepy.wait_for(25ms);
    REQUIRE(not_ready_yet == future_status::timeout);
    const auto totally_ready = sleepy.wait_for(100ms);
    REQUIRE(totally_ready == future_status::ready);
}

/**
 * Inefficient factorization algorithm to test concurrent programming.
 * @tparam T
 * @param x
 * @return
 */
template<typename T>
std::set<T> factorize(T x) {
    std::set<T> result{ 1 };
    for (T candidate{ 2 }; candidate <= x; candidate++) {
        if (x % candidate == 0) {
            result.insert(candidate);
            x /= candidate;
            candidate = 1;
        }
    }
    return result;
}

vector<uint64_t> factor_task(unsigned long x) {
    chrono::nanoseconds elapsed_ns;
    set<uint64_t> factors;
    {
        Stopwatch stopwatch{ elapsed_ns };
        factors = factorize<uint64_t>(x);
    }
    const auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(elapsed_ns).count();
    vector<uint64_t> result;
    result.push_back(x);
    result.push_back(elapsed_ms);
    for (auto factor : factors) {
        result.push_back(factor);
    }
    return result;
}

array<uint64_t, 6> numbers{
        9'699'690,
        179'426'549,
        1'000'000'007,
        4'294'967'291,
        4'294'967'296,
        1'307'674'368'000
};

TEST_CASE("factorize long") {
    chrono::nanoseconds elapsed_ns;
    {
        Stopwatch stopwatch{ elapsed_ns };
        vector<future<vector<uint64_t>>> factor_tasks;
        factor_tasks.reserve(numbers.size());
        for (auto number : numbers) {
            factor_tasks.emplace_back(async(launch::async, factor_task, number));
        }
        for (auto& task : factor_tasks) {
            vector<uint64_t> result = task.get();
            REQUIRE_FALSE(result.empty());
            auto number = result[0];
            auto time_ms = result[1];
            REQUIRE(result[0] >= 0);
            REQUIRE(result[1] >= 0);
            cout << time_ms << "ms: Factoring " << number << " ( ";
            auto it = result.begin() + 2;
            while (it != result.end()) {
                cout << *it << " ";
                REQUIRE(*it >= 1);
                REQUIRE(*it <= number);
                it++;
            }
            cout << " )" << endl;
        }
    }
    const auto total_program_time_ms = chrono::duration_cast<chrono::milliseconds>(elapsed_ns).count();
    cout << total_program_time_ms << "ms: total program time" << endl;
}

int goat_rodeo() {
    const size_t iterations{ 1'000'000 };
    int tin_cans_available{};
    mutex tin_can_mutex;

    auto eat_cans = async(launch::async, [&] {
        for (size_t i{}; i < iterations; i++) {
            lock_guard<mutex> guard{ tin_can_mutex };
            tin_cans_available--;
        }
    });

    auto deposit_cans = async(launch::async, [&] {
        for (size_t i{}; i < iterations; i++) {
            lock_guard<mutex> guard{ tin_can_mutex };
            tin_cans_available++;
        }
    });
    eat_cans.get();
    deposit_cans.get();
    return tin_cans_available;
}

TEST_CASE("goat_rodeo") {
    for (auto i = 0; i < 10; i++) {
        auto result = goat_rodeo();
        cout << "Goat rodeo: " << result << endl;
        REQUIRE(result == 0);
    }
}
