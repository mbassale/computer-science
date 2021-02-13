#include <cstdio>
#include <cstdint>


struct Tracer {
    Tracer(const char* name) : name{ name } {
        printf("%s constructed.\n", name);
    }
    ~Tracer() {
        printf("%s destructed.\n", name);
    }
private:
    const char* const name;
};


void play_scope() {
    Tracer main{ "main" };
    {
        printf("Block a\n");
        Tracer a1{ "a1" };
        Tracer a2{ "a2" };
    }
    {
        printf("Block b\n");
        Tracer b1{ "b1" };
        Tracer b2{ "b2" };
    }
}


void randomize(uint32_t&);


void play_declaration() {
    size_t iterations{};
    uint32_t number { 0x4c4347 };
    while (number != 0x474343) {
        randomize(number);
        ++iterations;
    }
    printf("Iterations: %zd\n", iterations);
}


int main() {
    play_scope();
    play_declaration();
    return 0;
}


void randomize(uint32_t& x) {
    x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000;
}
