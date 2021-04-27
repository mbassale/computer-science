#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <memory>
#include <stack>

struct empty_stack : public std::runtime_error
{
    empty_stack() : std::runtime_error("empty stack") {}
};

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack() {}
    
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        value = data.top();
        data.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

threadsafe_stack<int> ts_stack{};

void push_in_stack()
{
    for (int i = 0; i < 1000; i++) {
        std::cout << "Pushing: " << i << std::endl;
        ts_stack.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void pop_from_stack()
{
    // sleep waiting until the stack has elements
    while (ts_stack.empty())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    while (!ts_stack.empty()) {
        int value = 0;
        ts_stack.pop(value);
        std::cout << "Poping: " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

int main() {
    std::thread task1(push_in_stack);
    std::thread task2(pop_from_stack);
    task1.join();
    task2.join();
    return 0;
}
