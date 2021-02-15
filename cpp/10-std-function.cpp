#include <cstdio>
#include <cstdint>
#include <functional>

void static_func() {
    printf("A static function.\n");
}

struct CountIf {
    explicit CountIf(char x) : x{x} {}

    size_t operator()(const char* str) const {
        size_t index{}, result{};
        while (str[index]) {
            if (str[index] == x) result++;
            index++;
        }
        return result;
    }
private:
    const char x;
};

size_t count_spaces(const char* str) {
    size_t index{}, result{};
    while (str[index]) {
        if (str[index] == ' ') result++;
        index++;
    }
    return result;
}

int main() {
    {
        std::function<void()> func{[] { printf("A lamda.\n"); }};
        func();
        func = static_func;
        func();
    }

    {
        std::function<void()> func;
        try {
            func();
        } catch(const std::bad_function_call& e) {
            printf("Exception: %s\n", e.what());
        }
    }

    {
        std::function<size_t(const char*)> funcs[]{
                count_spaces,
                CountIf{ 'e' },
                [](const char* str) {
                    size_t index{};
                    while (str[index]) index++;
                    return index;
                }
        };
        auto text = "Sailor went to sea to see what he could see.";
        size_t index{};
        for (const auto& func : funcs) {
            printf("func #%zd: %zd\n", index++, func(text));
        }
    }
    return 0;
}