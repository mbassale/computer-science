#include <cstdio>

class ClockOfTheLongNow {
    int year{ 2019 };
public:
    ClockOfTheLongNow(int new_year = 2019) {
        year = new_year;
    }

    bool set_year(int year) {
        if (year < 2019) return false;
        this->year = year;
        return true;
    }

    int get_year() const {
        return year;
    }

    void add_year() {
        year++;
    }
};

struct College {
    char name[256];
};

void print_college_name(College* college_ptr, const char *prefix = nullptr) {
    if (prefix) {
        printf("%s %s\n", prefix, college_ptr->name);
    } else {
        printf("%s College\n", college_ptr->name);
    }
}

void print_college_names(College* colleges, size_t n_colleges) {
    for (size_t i = 0; i < n_colleges; i++) {
        printf("%s College\n", colleges[i].name);
    }
}

void play_pointers() {
    printf("***** Play Pointers *****\n");
    int gettysburg{};
    printf("Gettysburg: %d\n", gettysburg);
    int *gettysburg_address = &gettysburg;
    printf("Gettysburg address: %p\n", gettysburg_address);
    *gettysburg_address = 17365;
    printf("Gettysburg address: %d\n", *gettysburg_address);
    printf("Gettysburg: %d\n", gettysburg);

    ClockOfTheLongNow clock{2020};
    ClockOfTheLongNow *clock_ptr = &clock;
    clock_ptr->set_year(2021);
    printf("Address of clock: %p\n", clock_ptr);
    printf("Clock's year: %d\n", clock_ptr->get_year());
    printf("Clock's year #2: %d\n", (*clock_ptr).get_year());

    int key_to_the_universe[]{3, 6, 9};
    int *key_ptr = key_to_the_universe;

    College best_colleges[] = {"Magdalen", "Nuffield", "Kellogg"};
    print_college_name(best_colleges);
    printf("\n");
    print_college_names(best_colleges, sizeof(best_colleges) / sizeof(College));
    printf("\n");
    College *third_college_ptr = &best_colleges[2];
    print_college_name(third_college_ptr, "Third College:");
    College *third_college_ptr2 = best_colleges + 2;
    print_college_name(third_college_ptr2, "Third College:");
}

struct Element {
    Element* next{};

    void insert_after(Element* new_element) {
        new_element->next = next;
        next = new_element;
    }

    char prefix[2];
    short operating_number;
};

struct Avout {
    const char* name = "Erasmas";
    ClockOfTheLongNow apert;

    Avout(const char* name, int year_of_the_apert) : name(name), apert{year_of_the_apert} {
    }

    void announce() {
        printf("My name is %s and my next apert is %d\n", name, apert.get_year());
    }
};

void clock_add_year(ClockOfTheLongNow &clock) {
    clock.set_year(clock.get_year() + 1);
}

bool is_leap_year(const ClockOfTheLongNow &clock) {
    if (clock.get_year() % 4 > 0) return false;
    if (clock.get_year() % 100 > 0) return false;
    if (clock.get_year() % 400 > 0) return false;
    return true;
}

void play_references() {
    printf("***** Play References *****\n");

    ClockOfTheLongNow clock{2020};
    clock_add_year(clock);
    printf("Clock's year: %d\n", clock.get_year());

    Element trooper1, trooper2, trooper3;
    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    trooper1.insert_after(&trooper2);
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3);
    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 5;

    for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("stormtrooper: %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    }

    // Constant members
    Avout raz{ "Erasmas", 3010 };
    Avout jad{ "Jad", 4000 };
    raz.announce();
    jad.announce();
}

void play_auto() {
    // Auto variables
    auto the_answer { 42 }; // int
    auto foot { 12L }; // long
    auto rootbeer { 5.0F }; // float
    auto cheeseburger { 10.0 }; // double
    auto politifact_claims { false }; // bool
    auto cheese { "string" }; // char[7] 

    // Auto references
    auto year { 2019 }; // int
    auto& year_ref = year; // int&
    const auto& year_cref = year; // const int&
    auto* year_ptr = &year; // int*
    const auto* year_cptr = &year; // const int* 
}

int main() {
    play_pointers();
    printf("\n");
    play_references();
    printf("\n");
    play_auto();
    printf("\n");
    return 0;
}
