#include <stdexcept>
#include <cstdio>

#define trace_line (printf("Line: %d\n", __LINE__))

struct RatThing {
    static thread_local int rat_things_power;

    static void power_up_rat_thing(int nuclear_isotopes) {
        rat_things_power = rat_things_power + nuclear_isotopes;

        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10000) {
            printf("Warning! Hot doggie!\n");
        }
    }
};

thread_local int RatThing::rat_things_power = 200;

struct Tracer {
private:
    const char* name;

public:
    Tracer(const char* name) : name{name} {
        printf("%s constructed.\n", name);
    }

    ~Tracer() {
        printf("%s destructed.\n", name);
    }
};

void play_static_storage() {
    printf("Rat-thing power: %d\n", RatThing::rat_things_power);
    RatThing::power_up_rat_thing(100);
    printf("Rat-thing power: %d\n", RatThing::rat_things_power);
    RatThing::power_up_rat_thing(500);
    printf("Rat-thing power: %d\n", RatThing::rat_things_power);    
}

static Tracer t1{"Static variable"};
thread_local Tracer t2{"Thread-local variable"};

void play_dynamic_storage() {
    int* my_int_array_ptr = new int[100];
    delete[] my_int_array_ptr;
    trace_line;
    Tracer t3{"Automatic variable"};
    trace_line;
    const auto* t4 = new Tracer{"Dynamic variable"};
    trace_line;
}

struct Groucho {
    void forget(int x) {
        if (x == 0xFACE) {
            throw std::runtime_error{"I'd be glad to make an exception."};
        }
        printf("Forgot 0x%x\n", x);
    }
};

void play_exceptions() {
    Groucho groucho;
    try {
        groucho.forget(0xC0DE);
        groucho.forget(0xFACE);
        groucho.forget(0xC0FFEE);
    } catch (const std::runtime_error& e) {
        printf("exception caught with message: %s\n", e.what());
    }
}

int main() {
    printf("***** Static and Thread Local Allocation *****\n");
    play_static_storage();
    printf("\n");
    printf("***** Dynamic Storage *****\n");
    play_dynamic_storage();
    printf("\n");
    printf("***** Exceptions *****\n");
    play_exceptions();
    printf("\n");
    return 0;
}
