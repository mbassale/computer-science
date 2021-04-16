#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

struct func
{
    int& i;
    func(int& i_) : i(i_) {}
    void operator()() 
    {
        for (unsigned j = 0; j < 1000; j++) {
            i++;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
};

void call_that_throws_exception() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Throwing exception!\n";
    throw std::runtime_error("dummy exception.");
}

void f()
{
    int some_local_var = 0;
    func func1(some_local_var);
    std::thread task1(func1);
    try {
        call_that_throws_exception();
    }
    catch(...) {
        task1.join();
        throw;
    }
    task1.join();
}

int main() {
    try {
        f();
    }
    catch(std::runtime_error& e) {
        std::cout << "Stopping exception.\n";
    }
    return 0;
}

