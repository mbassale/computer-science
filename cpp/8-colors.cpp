#include <cstdint>
#include <cstdio>

struct Color {
    float H, S, V;
};

constexpr uint8_t max(uint8_t a, uint8_t b) {
    return a > b ? a : b;
}

constexpr uint8_t max(uint8_t a, uint8_t b, uint8_t c) {
    return max(max(a, b), max(a, c));
}

constexpr uint8_t min(uint8_t a, uint8_t b) {
    return a < b ? a : b;
}

constexpr uint8_t min(uint8_t a, uint8_t b, uint8_t c) {
    return min(min(a, b), min(a, c));
}

constexpr float module(float dividend, float divisor) {
    const auto quotient = dividend / divisor;
    return divisor * (quotient - static_cast<uint8_t>(quotient));
}

constexpr Color rgb_to_hsv(uint8_t r, uint8_t g, uint8_t b) {
    Color c{};
    const auto c_max = max(r, g, b);
    c.V = c_max / 255.0f;

    const auto c_min = min(r, g, b);
    const auto delta = c.V - c_min / 255.0f;
    c.S = c_max == 0 ? 0 : delta / c.V;

    if (c_max == c_min) {
        c.H = 0;
        return c;
    }

    if (c_max == r) {
        c.H = (g / 255.0f -  b / 255.0f) / delta;
    } else if (c_max == g) {
        c.H = (b / 255.0f - r / 255.0f) / delta + 2.0f;
    } else if (c_max == b) {
        c.H = (r / 255.0f - g / 255.0f) / delta + 4.0f;
    }

    c.H *= 60.0f;
    c.H = c.H >= 0.0f ? c.H : c.H + 360.0f;
    c.H = module(c.H, 360.0f);
    return c;
}

void print_hsv(Color &color) {
    printf("%.2f %.2f %.2f\n", color.H, color.S, color.V);
}

int main() {

    auto black = rgb_to_hsv(0, 0, 0);
    print_hsv(black);
    auto white = rgb_to_hsv(255, 255, 255);
    print_hsv(white);
    auto red = rgb_to_hsv(255, 0, 0);
    print_hsv(red);
    auto green = rgb_to_hsv(0, 255, 0);
    print_hsv(green);
    auto blue = rgb_to_hsv(0, 0, 255);
    print_hsv(blue);

    return 0;
}