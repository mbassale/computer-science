#include <limits>
#include <cstdio>
#include <cstdint>

struct ReadOnlyInt {
    ReadOnlyInt(int val) : val{ val } {}
    explicit operator int() const {
        return val;
    }
private:
    const int val;
};

void print_addr(void* x) {
    printf("%p\n", x);
}

void trainwreck(const char* read_only) {
    auto as_unsigned = (unsigned char*)read_only;
    *as_unsigned = 'b';
}

int main() {
    /**
     * Float conversions
     */
    double x = std::numeric_limits<float>::max();
    long double y = std::numeric_limits<double>::max();
    float z = std::numeric_limits<long double>::max(); // undefined behaviour
    printf("x: %g\ny: %Lg\nz: %g\n", x, y, z);

    /**
     * Pointer to void*
     */
    int num1{};
    print_addr(&num1);
    print_addr(nullptr);

    /**
     * Explicit type conversion
     */
    int32_t num_a = 100;
    int64_t num_b{ num_a };
    if (num_a == num_b) printf("Non-narrowing conversion!\n");
    //int32_t num_c{ num_b }; // Error!

    int64_t num_d = std::numeric_limits<int64_t>::max();
    int32_t num_e(num_d);
    if (num_d != num_e) printf("Narrowing conversion! %lld -> %d\n", num_d, num_e);

    /**
     * C-style casts
     */
    auto ezra = "Ezra";
    printf("Before trainwreck: %s\n", ezra);
    //trainwreck(ezra);
    //printf("After trainwreck: %s\n", ezra);

    /**
     * User-defined conversions
     */
    ReadOnlyInt the_answer{ 42 };
    auto ten_answers = static_cast<int>(the_answer) * 10;
    printf("Ten answers: %d\n", ten_answers);
    return 0;
}