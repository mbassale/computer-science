#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

class X
{
    int id;
public:
    explicit X(int id_) : id(id_) {}
    void do_work()
    {
        std::cout << "Id: " << id << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
};

void test1() 
{
    X the_x{1};
    std::thread task1(&X::do_work, &the_x);
    task1.join();    
}

void test2()
{
    X the_x{2};
    std::thread task2(std::bind(&X::do_work, &the_x));
    task2.join();
}

int main()
{
    test1();
    test2();
    return 0;
}