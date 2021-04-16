#include <iostream>
#include <thread>

int main() {
    std::thread thread1([]{
        std::cout << "Called from inside a lambda-thread.\n";
    });
    thread1.join();
    return 0;
}