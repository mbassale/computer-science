#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

class scoped_thread
{
    std::thread t;
    public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
        if (!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread &operator=(scoped_thread const &) = delete;
};

struct func
{
    int& i;
    func(int& i_) : i(i_) {}
    void operator()() 
    {
        std::cout << "Doing work in functor... " << std::flush;
        for (unsigned j = 0; j < 1000; j++) {
            i++;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        std::cout << "Done.\n";
    }
};

void f() {
    int some_local_state;
    scoped_thread t{std::thread(func(some_local_state))};
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
    f();
    return 0;
}
