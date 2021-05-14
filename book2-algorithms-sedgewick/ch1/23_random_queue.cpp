#include <iostream>
#include <memory>
#include <stdexcept>
#include <random>

template<typename T>
class RandomQueue {
private:
    static constexpr size_t
    default_capacity = 10;
    std::unique_ptr<T[]> _data;
    size_t _size{};
    size_t _capacity{};
    std::random_device rd;
    std::mt19937 gen;

public:
    class RandomQueueIterator {
    private:
        T *data;
        size_t size;
        std::unique_ptr<size_t[]> indices{};
        size_t current_index = 0;
    public:
        RandomQueueIterator(T *data, size_t size, size_t start = 0) {
            this->data = data;
            this->size = size;
            current_index = start;
            indices = std::unique_ptr<size_t[]>(new size_t[size]);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution <size_t> dist(0, size - 1);
            for (size_t i = 0; i < size; i++) {
                indices[i] = dist(gen);
            }
        }

        T operator*() { return data[indices[current_index]]; }

        bool operator==(const RandomQueueIterator &rhs) { return current_index == rhs.current_index; }

        bool operator!=(const RandomQueueIterator &rhs) { return current_index != rhs.current_index; }

        RandomQueueIterator &operator++() {
            current_index++;
            return *this;
        }

        RandomQueueIterator operator++(int) {
            RandomQueueIterator tmp{data, size};
            operator++();
            return tmp;
        }
    };

    RandomQueue() : rd(), gen(rd()) {
        _data = std::unique_ptr<T[]>(new T[default_capacity]);
        _capacity = default_capacity;
    };

    ~RandomQueue() = default;

    [[nodiscard]] size_t size() const { return _size; }

    [[nodiscard]] bool empty() const { return _size == 0; }

    void enqueue(const T &item) {
        _data[_size++] = item;
        if (_size == _capacity) {
            resize(2 * _capacity);
        }
    }

    T dequeue() {
        auto val = _data[--_size];
        if (_size < _capacity / 4) resize(_capacity / 2);
        return val;
    }

    T sample() {
        std::uniform_int_distribution <size_t> dist(0, _size - 1);
        auto index = dist(gen);
        return _data[index];
    }

    auto begin() {
        if (empty()) end();
        return RandomQueueIterator(_data.get(), _size, 0);
    }

    auto end() {
        return RandomQueueIterator(_data.get(), _size, _size);
    }

private:
    void resize(size_t new_capacity) {
        auto new_data = std::unique_ptr<T[]>(new T[new_capacity]);
        for (size_t i = 0; i < _size; i++)
            new_data[i] = _data[i];
        _data = std::move(new_data);
        _capacity = new_capacity;
    }
};

int main() {
    using namespace std;

    cout << "Random Queue" << endl;
    RandomQueue<int> rq;

    for (int i = 1; i <= 10; i++) {
        rq.enqueue(i);
        cout << "Enqueued: " << i << " Size: " << rq.size() << endl;
    }

    cout << "Sample: ";
    for (int i = 0; i < 10; i++) {
        cout << rq.sample() << " ";
    }
    cout << endl;

    cout << "Random Iterator: ";
    for (auto i : rq) {
        cout << i << " ";
    }
    cout << endl;

    while (rq.size()) {
        cout << "Dequeued: " << rq.dequeue() << " Size: " << rq.size() << endl;
    }

    return 0;
}
