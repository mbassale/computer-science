#include <cstdio>
#include <stdexcept>

template<typename X, typename Y, typename Z>
struct MyTemplateClass {
    X foo(Y&);
private:
    Z* member;
};

short increment_as_short(void* target) {
    auto as_short = static_cast<short*>(target);
    *as_short = *as_short + 1;
    return *as_short;
}

template <typename To, typename From>
To narrow_cast(From value) {
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if (value != backwards) throw std::runtime_error{ "Narrowed!" };
    return converted;
}

template<typename T>
T mean(const T values[], size_t length) {
    T result{};
    for (size_t i{}; i < length; i++) {
        result += values[i];
    }
    return result / length;
}

int main() {
    short beast{ 665 };
    auto mark_of_the_beast = increment_as_short(&beast);
    printf("%d is the mark of the beast.\n", mark_of_the_beast);

    auto timer = reinterpret_cast<const unsigned long*>(0x1000);
    //printf("Timer is %lu\n", *timer);

    int perfect{ 496 };
    const auto perfect_short = narrow_cast<short>(perfect);
    printf("perfect_short: %d\n", perfect_short);
    try {
        int cyclic{ 142857 };
        const auto cyclic_short = narrow_cast<short>(cyclic);
        printf("cyclic_short: %d\n", cyclic_short);
    } catch(const std::runtime_error& e) {
        printf("Exception: %s\n", e.what());
    }

    const double nums_d[] { 1.0, 2.0, 3.0, 4.0 };
    const auto result1 = mean<double>(nums_d, 4);
    printf("double mean: %f\n", result1);

    const float nums_f[] { 1.0f, 2.0f, 3.0f, 4.0f };
    const auto result2 = mean<float>(nums_f, 4);
    printf("float mean: %f\n", result2);

    const size_t nums_c[] { 1, 2, 3, 4 };
    const auto result3 = mean(nums_c, 4);
    printf("size_t mean: %zd\n", result3);

    return 0;
}