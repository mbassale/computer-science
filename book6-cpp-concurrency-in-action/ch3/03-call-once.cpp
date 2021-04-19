#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include <vector>

struct func
{
    func() 
    {
        std::cout << "Functor constructor" << std::endl;
    }

    void operator()()
    {
        std::cout << "Doing work in functor... " << std::flush;
        for (unsigned j = 0; j < 1000; j++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        std::cout << "Done.\n";
    }
};

std::shared_ptr<func> resource_ptr;
std::once_flag resource_flag;

void init_resource()
{
    resource_ptr.reset(new func());
}

void factory()
{
    std::call_once(resource_flag, init_resource);
    (*resource_ptr)();
}

int main() 
{
    std::vector<std::thread> tasks{};
    size_t num_threads = std::thread::hardware_concurrency();
    while (num_threads > 0) {
        tasks.push_back(std::thread(factory));
        num_threads--;
    }
    for (auto& task : tasks) {
        task.join();
    }
    return 0;
}