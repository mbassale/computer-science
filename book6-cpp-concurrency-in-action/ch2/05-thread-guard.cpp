#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>

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

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {}
    ~thread_guard()
    {
        if (t.joinable()) {
            std::cout << "Joining thread." << std::endl;
            t.join();
        }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};

void f()
{
    int some_local_var = 0;
    func func1(some_local_var);
    std::thread task1(func1);
    thread_guard g(task1);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
    f();
    return 0;
}