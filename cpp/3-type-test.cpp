#include <climits>
#include <cstddef>
#include <cstdio>
#include <iterator>

enum class Race {
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan
};

struct Book {
    char name[256];
    int year;
    int pages;
    int hardcover;
};

class ClockOfTheLongNow {
    int year{ 2019 };
public:
    ClockOfTheLongNow(int new_year = 2019) {
        year = new_year;
    }

    bool set_year(int new_year) {
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }

    int get_year() {
        return year;
    }

    void add_year() {
        year++;
    }
};

struct PodStruct {
    uint64_t a;
    char b[256];
    bool c;
};

int main() {
    // Integer types.
    unsigned short a = 0b10101010; 
    printf("%hu\n", a);
    int b = 0123; 
    printf("%d\n", b);
    unsigned long long c = 0xFFFFFFFFFFFFFFFF;
    printf("%llu\n", c);
    unsigned int d = 3669732608;
    printf("Yabba %x!\n", d);
    unsigned int e = 69;
    printf("There are %u ➋ ,%o ➌ leaves here.\n", e, e);
    
    // Floating types.
    double an = 6.0221409e23; 
    printf("Avogadro's Number: %le ➋ %lf ➌ %lg ➍ \n", an, an, an);
    float hp = 9.75;
    printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);

    // Char types.
    char char1 = 'M';
    wchar_t char2 = L'M';
    printf("Characters: %c %lc\n", char1, char2);

    // Size of types.
    size_t char_size = sizeof(char);
    printf("char: %zd\n", char_size);
    size_t short_size = sizeof(short);
    printf("short: %zd\n", short_size);
    size_t int_size = sizeof(int);
    printf("int: %zd\n", int_size);
    size_t long_size = sizeof(long);
    printf("long: %zd\n", long_size);
    size_t long_long_size = sizeof(long long);
    printf("long long: %zd\n", long_long_size);

    // Arrays.
    int array1[100];
    int array2[] = {1, 2, 3, 4};
    int max_value = INT_MIN;

    // Traditional for loops.
    for (size_t i = 0; i < 4; i++) {
        if (array2[i] > max_value) {
            max_value = array2[i];
        }
    }
    printf("Max Value: %d\n", max_value);

    // Range-based loops.
    unsigned long max_value2 = 0;
    unsigned long array3[] = {10, 20, 30, 40, 50, 60, 0};
    for (unsigned long value : array3) {
        if (value > max_value2) {
            max_value2 = value;
        }
    }
    printf("Max Value2: %lu\n", max_value2);

    // Array/Container sizes.
    size_t array3_len = sizeof(array3) / sizeof(unsigned long);
    printf("Array3 Length: %zd\n", array3_len);
    size_t array3_len2 = std::size(array3);
    printf("Array3 std::size: %zd\n", array3_len2);

    // Literal strings.
    char english_str[] = "A book holds a house of gold.";
    printf("English: %s\n", english_str);
    char16_t chinese_str[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

    // Enumeration types (Scoped enum)
    Race langobard_race = Race::Aidan;
    printf("Race: %d\n", langobard_race);

    // Plain-Old-Data Classes (Structs)
    Book neuromancer { "Neuromancer", 1980, 300, 1 };
    printf("Book: %s Year: %d, Pages: %d, Hardcover? %d\n", neuromancer.name, neuromancer.year, neuromancer.pages, neuromancer.hardcover);


    // Classes
    ClockOfTheLongNow clock;
    printf("Year: %d\n", clock.get_year());
    clock.add_year();
    printf("Year: %d\n", clock.get_year());

    // POD Initialization
    PodStruct pod1{};
    PodStruct pod2 = {};
    PodStruct pod3 = { 42, "Hello" };
    PodStruct pod4 = { 42, "Hello", true };


    printf("\n");
    return 0;
}
