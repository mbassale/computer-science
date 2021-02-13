#include <cstdio>
#include <cstdint>
#include <type_traits>

constexpr const char* as_str(bool b) { return b ? "True" : "False"; }

template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
    static_assert(Index < Length, "Out-of-bounds access");
    return arr[Index];
}

int main() {
    printf("%s\n", as_str(std::is_integral<int>::value));
    printf("%s\n", as_str(std::is_integral<const int>::value));
    printf("%s\n", as_str(std::is_integral<char>::value));
    printf("%s\n", as_str(std::is_integral<uint64_t>::value));
    printf("%s\n", as_str(std::is_integral<int&>::value));
    printf("%s\n", as_str(std::is_integral<int*>::value));
    printf("%s\n", as_str(std::is_integral<float>::value));

    int fib[] { 1, 1, 2, 3, 5 };
    printf("fib<3>: %d\n", get<3>(fib));
    //get<9>(fib);
    return 0;
}