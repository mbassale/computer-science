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
    size_t _capacity{};
    size_t _size{};
public:
    MaxPQ(size_t capacity = 1) : _capacity(capacity) {
        items.resize(_capacity + 1);
    }

    [[nodiscard]] bool empty() const { return _size == 0; }
    [[nodiscard]] bool full() const { return _size == _capacity; }
    [[nodiscard]] size_t size() const { return _size; }
    [[nodiscard]] size_t capacity() const { return _capacity; }

    void insert(const T& item) {
        if (_size >= 1 && items[_size] < item) {
            items[_size] = item;
            swim(_size);
        } else if (_size >= 2 && items[_size - 1] < item) {
            items[_size - 1] = item;
            swim(_size);
        } else if (!full()) {
            items[++_size] = item;
            swim(_size);
        }
    }

    T& max() {
        if (empty()) throw std::runtime_error("MaxPQ empty.");
        return items[1];
    }

    T& delete_max() {
        auto max = items[1];
        swap(1, _size--);
        sink(1); // restore heap ordering.
        return max;
    }

private:
    void swim(size_t index) {
        while (index > 1 && less(index / 2, index)) {
            swap(index / 2, index);
            index = index / 2;
        }
    }

    void sink(size_t index) {
        while (2 * index <= size()) {
            size_t j = 2 * index;
            if (j < size() && less(j, j + 1)) j++;
            if (!less(index, j)) break;
            swap(index, j);
            index = j;
        }
    }

    bool less(size_t i, size_t j) {
        return items[i] < items[j];
    }

    void swap(size_t i, size_t j) {
        auto tmp = items[i];
        items[i] = items[j];
        items[j] = tmp;
    }
};

int main(int argc, char* argv[]) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    std::cout << "MaxPQ: Maximum Priority Queue with Binary Heap." << std::endl;

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

    std::cout << "Feeding priority queue:" << std::flush;
    MaxPQ<long> max_priority_queue(10);
    auto it = numbers.begin();
    while (it != numbers.end()) {
        max_priority_queue.insert(*it);
        std::cout << "Insert: " << *it << " Max: " << max_priority_queue.max() << " Size: " << max_priority_queue.size() << std::endl;
        it++;
    }
    std::cout << "Done." << std::endl;

    return EXIT_SUCCESS;
}