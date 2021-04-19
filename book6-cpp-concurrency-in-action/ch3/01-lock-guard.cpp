#include <algorithm>
#include <vector>
#include <list>
#include <chrono>
#include <thread>
#include <mutex>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value) != some_list.end();
}

void add_numbers()
{
    for (int i = 0; i < 1000; i++)
    {
        add_to_list(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void check_numbers()
{
    for (int i = 0; i < 1000; i++)
    {
        list_contains(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

int main()
{
    std::vector<std::thread> threads;
    threads.push_back(std::thread(add_numbers));
    threads.push_back(std::thread(check_numbers));
    for (auto &task : threads)
    {
        task.join();
    }
    return 0;
}