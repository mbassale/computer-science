#include <thread>
#include <iostream>

class background_task {
    public:
    void operator()() const {
        std::cout << "Running thread in a functor.\n"; 
    }
};

int main() {
    background_task task;
    std::thread thread1(task);
    thread1.join();
    return 0;
}