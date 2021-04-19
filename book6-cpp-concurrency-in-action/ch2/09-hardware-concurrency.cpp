#include <algorithm>
#include <numeric>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

template <typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        std::cout << "Running Thread Id: " << std::this_thread::get_id() << std::endl;
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);
    if (!length)
        return init;
    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length / num_threads;
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);
    Iterator block_start = first;
    // launch threads except the last block that will be executed by this thread
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        std::cout << "Spawning thread: " << i << " " << std::endl;
        threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
        block_start = block_end;
    }
    // last block is executed by this thread
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    for (auto& entry : threads)
        entry.join();
    
    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::microseconds;

    std::cout << "hardware_concurrency: " << std::thread::hardware_concurrency() << std::endl;
    std::vector<uint64_t> numbers(1000000);
    auto it = numbers.begin();
    uint64_t num = 0;
    while (it != numbers.end()) {
        *it = num++;
        it++;
    }
    auto time1 = high_resolution_clock::now();
    auto result = parallel_accumulate(numbers.begin(), numbers.end(), 100000);
    auto time2 = high_resolution_clock::now();
    std::cout << "Parallel Accumulate: " << result << " Time: " << duration_cast<microseconds>(time2 - time1).count() << "us" << std::endl;

    time1 = high_resolution_clock::now();
    auto result2 = std::accumulate(numbers.begin(), numbers.end(), 100000);
    time2 = high_resolution_clock::now();
    std::cout << "Non-parallel Accumulate: " << result2 << " Time: " << duration_cast<microseconds>(time2 - time1).count() << "us" << std::endl;
    return 0;
}