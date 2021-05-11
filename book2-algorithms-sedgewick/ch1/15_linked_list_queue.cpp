#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

template<typename T>
class Queue {
private:
    struct Node {
        T item;
        std::shared_ptr<Node> next;
    };

    std::shared_ptr<Node> _last{};
    std::shared_ptr<Node> _first{};
    size_t _size{};

public:
    Queue() = default;

    [[nodiscard]] size_t size() { return _size; }
    [[nodiscard]] bool empty() { return _size == 0; }

    void enqueue(const T& item) {
        auto old_last = _last;
        auto new_last = std::make_shared<Node>();
        new_last->item = item;
        new_last->next = nullptr;
        _last = new_last;
        if (empty())
            _first = _last;
        else
            old_last->next = _last;
        _size++;
    }

    T dequeue() {
        if (empty()) throw std::runtime_error("empty queue");
        auto item = _first->item;
        _first = _first->next;
        _size--;
        if (empty()) _last = _first;
        return item;
    }
};

int main() {
    using namespace std;
    cout << "Queue Linked List Implementation" << endl;

    Queue<int> queue;

    cout << "IsEmpty? " << (queue.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        queue.enqueue(i);
        cout << "Enqueued: " << i << " Size: " << queue.size() << endl;
    }

    cout << "IsEmpty? " << (queue.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        cout << "Dequeued: " << queue.dequeue() << " Size: " << queue.size() << endl;
    }

    cout << "IsEmpty? " << (queue.empty() ? "true" : "false") << endl;

    return 0;
}
