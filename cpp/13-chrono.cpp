#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstdio>
#include <thread>
#include <chrono>

struct Stopwatch {
    Stopwatch(std::chrono::nanoseconds& result) : result{ result }, start{ std::chrono::high_resolution_clock::now() } {}
    ~Stopwatch() {
        result = std::chrono::high_resolution_clock::now() - start;
    }
private:
    std::chrono::nanoseconds& result;
    const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

TEST_CASE("std::chrono supports several clocks") {
    auto sys_now = std::chrono::system_clock::now();
    auto hires_now = std::chrono::high_resolution_clock::now();
    auto steady_now = std::chrono::steady_clock::now();

    REQUIRE(sys_now.time_since_epoch().count() > 0);
    REQUIRE(hires_now.time_since_epoch().count() > 0);
    REQUIRE(steady_now.time_since_epoch().count() > 0);
}

TEST_CASE("std::chrono supports several units of measurement") {
    using namespace std::literals::chrono_literals;
    auto one_s = std::chrono::seconds(1);
    auto thousand_ms = 1000ms;
    REQUIRE(one_s == thousand_ms);
}

TEST_CASE("std::chrono supports duration_cast") {
    using namespace std::chrono;
    auto billion_ns_as_s = duration_cast<seconds>(1'000'000'000ns);
    REQUIRE(billion_ns_as_s.count() == 1);
}

TEST_CASE("std::chrono used to sleep") {
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(100ms);
    auto end = std::chrono::system_clock::now();
    REQUIRE(end - start > 100ms);
}

TEST_CASE("std::chrono timing operations") {
    const size_t n = 1'000'000;
    std::chrono::nanoseconds elapsed;
    {
        Stopwatch stopwatch{ elapsed };
        volatile double result{ 1.23e45 };
        for (double i = 1; i < n; i++) {
            result /= i;
        }
    }
    auto time_per_division = elapsed.count() / double{ n };
    REQUIRE(time_per_division > 0);
    printf("Took %gns per division.\n", time_per_division);
}