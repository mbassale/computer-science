#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

struct big_data
{
    uint64_t data1;
    uint64_t data2;
    uint64_t data3;
    uint64_t data4;
};

void process_big_data(std::unique_ptr<big_data> data)
{
    std::cout << "Processing big data: " << data->data1 << "," << data->data2 << "," << data->data3 << "," << data->data4 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main() 
{
    std::unique_ptr<big_data> data(new big_data);
    data->data1 = 1;
    data->data2 = 2;
    data->data3 = 3;
    data->data4 = 4;
    std::thread task1(process_big_data, std::move(data));
    task1.join();
    return 0;
}