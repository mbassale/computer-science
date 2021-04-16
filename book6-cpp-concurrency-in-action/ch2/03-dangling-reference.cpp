#include <iostream>
#include <chrono>
#include <thread>

struct func
{
    int& i;
    func(int& i_) : i(i_) {}
    void operator()() 
    {
        for (unsigned j = 0; j < 1000; j++) {
            std::cout << "Var: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
};

void oops() 
{
    int some_local_var = 0;
    func func1(some_local_var);
    std::thread task1(func1);
    task1.detach();
}

int main() {
    std::thread main_task(oops);
    main_task.join();
    return 0;
}