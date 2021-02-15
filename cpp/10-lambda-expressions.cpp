#include <cstdio>
#include <cstdint>

template <typename Fn, typename T>
void transform(Fn fn, const T* in, T* out, size_t length) {
    for (size_t i{}; i < length; i++) {
        out[i] = fn(in[i]);
    }
}

int main() {
    const size_t len{ 3 };
    int base[]{ 1, 2, 3 }, a[len], b[len], c[len];
    float base_float[]{ 10.f, 20.f, 30.f }, d[len];
    transform([](int x) { return 1; }, base, a, len);
    transform([](int x) { return x; }, base, b, len);
    transform([](int x) { return 10*x+5; }, base, c, len);
    transform([](auto x) { return 10*x+5; }, base_float, d, len);
    for (size_t i{}; i < len; i++) {
        printf("Element %zd: %d %d %d %f\n", i, a[i], b[i], c[i], d[i]);
    }

    auto increment = [](auto x, int y = 1) { return x + y; };
    printf("increment(10) = %d\n", increment(10));
    printf("increment(10, 5) = %d\n", increment(10, 5));
    return 0;
}