#include <ctime>
#include <cstdio>
#include <utility>
#include <exception>
#include <chrono>

using namespace std::chrono;

struct TimerClass {
    TimerClass(const char* name = "Unknown timer") : name{name} { 
        timestamp = high_resolution_clock::now(); 
    }

    TimerClass(const TimerClass& other) : name{other.name}, timestamp{other.timestamp} {}

    TimerClass(TimerClass&& other) {
        name = other.name;
        timestamp = other.timestamp;
        other.timestamp = high_resolution_clock::time_point(high_resolution_clock::duration(0L));
    }

    ~TimerClass() {
        time_point current_time = high_resolution_clock::now();
        printf("Timer %s: %lld\n", name, (current_time - timestamp).count());
    }

    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        return *this;
    }

    TimerClass& operator=(TimerClass&& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        other.timestamp = high_resolution_clock::time_point(high_resolution_clock::duration(0L));
        return *this;
    }
private:
    const char* name;
    high_resolution_clock::time_point timestamp;
};

int main() {
    TimerClass timer1{"timer1"};
    TimerClass timer2{timer1};
    TimerClass timer3{TimerClass{"TempTimer"}};
    return 0;
}