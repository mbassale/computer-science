#include <cstdio>

float add(float a, int b) {
    return a + b;
}

float subtract(float a, int b) {
    return a - b;
}

using operation_func = float(*)(float, int);

int main() {
    const float first{ 100 };
    const int second{ 20 };

    operation_func operation{};
    printf("operation initialized to %p\n", operation);

    operation = &add;
    printf("&add = %p\n", operation);
    printf("%g + %d = %g\n", first, second, operation(first, second));

    operation = &subtract;
    printf("&subtract = %p\n", operation);
    printf("%g - %d = %g\n", first, second, operation(first, second));

    return 0;
}