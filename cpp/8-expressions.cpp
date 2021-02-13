#include <cstdio>
#include <stdexcept>

struct CheckedInteger {
    CheckedInteger(unsigned int value) : value{ value } {}

    CheckedInteger operator+(unsigned int other) const {
        CheckedInteger result{ value + other };
        if (result.value < value) throw std::runtime_error("Overflow!");
        return result;
    }

    const unsigned int value;
};


int main() {
    CheckedInteger a{ 100 };
    auto b = a + 200;
    printf("a + 200 = %u\n", b.value);
    try {
        auto c = a + std::numeric_limits<unsigned int>::max();
    } catch(const std::runtime_error& e) {
        printf("(a + max) Exception: %s\n", e.what());
    }
    return 0;
}