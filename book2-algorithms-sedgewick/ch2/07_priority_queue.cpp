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
    MaxPQ() = default;

    MaxPQ(size_t capacity) : _capacity(capacity) {
        items.resize(_capacity);
    }

    [[nodiscard]] bool empty() const { return _size == 0; }
    [[nodiscard]] size_t size() const { return _size; }
    [[nodiscard]] size_t capacity() const { return _capacity; }

    void insert(const T& key) {
        
    }

    T& max() {

    }

    T& delete_max() {

    }
};