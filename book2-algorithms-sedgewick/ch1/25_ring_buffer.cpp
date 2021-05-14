#include <iostream>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>

template<typename T>
class RingBuffer {
private:
    std::mutex _mutex;
    size_t _capacity;
    std::unique_ptr<T[]> _data;
    size_t _head = 0;
    size_t _tail = 0;
    bool _full = false;

public:
    RingBuffer(size_t capacity) : _data(std::unique_ptr<T[]>(new T[capacity])), _capacity(capacity) {
    }

    [[nodiscard]] bool empty() const { return (!_full && (_head == _tail)); }

    [[nodiscard]] bool full() const { return _full; }

    [[nodiscard]] size_t capacity() const { return _capacity; }

    [[nodiscard]] size_t size() const {
        auto _size = _capacity;
        if (!_full) {
            if (_head >= _tail) _size = _head - _tail;
            else _size = _capacity + _head - _tail;
        }
        return _size;
    }

    void reset() {
        std::lock_guard <std::mutex> lock(_mutex);
        _head = _tail;
        _full = false;
    }

    void put(const T &item) {
        std::lock_guard <std::mutex> lock(_mutex);
        _data[_head] = item;
        if (_full) {
            _tail = (_tail + 1) % _capacity;
        }
        _head = (_head + 1) % _capacity;
        _full = _head == _tail;
    }

    std::optional <T> get() {
        std::lock_guard <std::mutex> lock(_mutex);
        if (empty()) return std::nullopt;
        auto val = _data[_tail];
        _full = false;
        _tail = (_tail + 1) % _capacity;
        return val;
    }
};

int main() {
    using namespace std;
    cout << "Ring Buffer using unique_ptr and locks." << endl;

    RingBuffer<int> ring_buffer(10);

    auto print_details = [&]() {
        cout << "Size: " << (ring_buffer.size()) << " IsEmpty? " << (ring_buffer.empty() ? "true" : "false")
             << " IsFull? "
             << (ring_buffer.full() ? "true" : "false") << endl;
    };
    print_details();

    for (int i = 1; i <= 15; i++) {
        ring_buffer.put(i);
        cout << "Putting: " << i << " Size: " << ring_buffer.size() << endl;
    }

    print_details();

    while (ring_buffer.size()) {
        auto val = ring_buffer.get();
        cout << "Getting: " << *val << " Size: " << ring_buffer.size() << endl;
    }

    print_details();

    return EXIT_SUCCESS;
}
