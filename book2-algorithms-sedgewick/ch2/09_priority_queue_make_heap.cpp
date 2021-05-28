#include <iostream>
#include <algorithm>
#include <utility>
#include <random>
#include <string>
#include <vector>
#include <chrono>

template<typename T>
class MaxPQ {
private:
    std::vector<T> items;
public:
    static constexpr size_t DefaultCapacity = 1;

    MaxPQ(size_t capacity = DefaultCapacity) {
        items.reserve(capacity);
    }

    [[nodiscard]] bool empty() const { return items.empty(); }
    [[nodiscard]] size_t size() const { return items.size(); }
    [[nodiscard]] size_t capacity() const { return items.capacity(); }

    void insert(const T& item) {
        items.push_back(item);
        std::push_heap(items.begin(), items.end());
    }

    T& max() {
        if (empty()) throw std::runtime_error("MaxPQ empty.");
        return items.front();
    }

    T delete_max() {
        auto max_num = max();
        std::pop_heap(items.begin(), items.end());
        items.pop_back();
        return max_num;
    }
};

int main(int argc, char* argv[]) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    std::cout << "MaxPQ: Maximum Priority Queue with STL make_heap function." << std::endl;

    if (argc <= 1) {
        std::cerr << "Missing number of elements." << std::endl;
        return EXIT_FAILURE;
    }

    size_t numbers_length = std::stoi(argv[1]);
    std::cout << "Number of Elements: " << numbers_length << std::endl;

    std::cout << "Generating data... " << std::flush;
    std::vector<long> numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <size_t> dist(0, 1000000);
    while (numbers_length > 0) {
        numbers.push_back(dist(gen));
        numbers_length--;
    }
    std::cout << "Done." << std::endl;

    if (numbers.size() < 100) {
        auto it = numbers.begin();
        std::cout << "Numbers: ";
        while (it != numbers.end()) {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
    }

    std::cout << "Feeding priority queue:" << std::endl;
    MaxPQ<long> max_priority_queue(10);
    auto it = numbers.begin();
    while (it != numbers.end()) {
        max_priority_queue.insert(*it);
        std::cout << "Insert: " << *it << " Max: " << max_priority_queue.max() << " Size: " << max_priority_queue.size() << std::endl;
        it++;
    }
    std::cout << "Done." << std::endl;

    std::cout << "Popping from priority queue:" << std::endl;
    while (max_priority_queue.size() > 0) {
        auto max_num = max_priority_queue.delete_max();
        std::cout << "Max: " << max_num << " Size: " << max_priority_queue.size() << std::endl;
    }

    return EXIT_SUCCESS;
}