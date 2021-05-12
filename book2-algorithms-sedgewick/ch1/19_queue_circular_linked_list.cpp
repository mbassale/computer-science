#include <iostream>
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
    size_t _size{};

public:
    struct QueueIterator {
        std::shared_ptr<Node> p;
        QueueIterator(const std::shared_ptr<Node>& p) : p(p) {}
        QueueIterator(const QueueIterator& it) : p(it.p) {}
        T& operator*() { return p->item; }
        bool operator==(const QueueIterator& rhs) { return p == rhs.p; }
        bool operator!=(const QueueIterator& rhs) { return p != rhs.p; }
        QueueIterator& operator++() { p = p->next; return *this; }
        QueueIterator operator++(int) { 
            QueueIterator tmp(*this);
            operator++();
            return tmp;
        }
    };

    Queue() = default;
    ~Queue() {
        if (_last) {
            _last->next = nullptr;
        }
    }

    [[nodiscard]] bool empty() { return _size == 0; }
    [[nodiscard]] size_t size() { return _size; }

    void enqueue(const T& item) {
        auto new_last = std::make_shared<Node>();
        new_last->item = item;
        if (_last)  {
            new_last->next = _last->next;
            _last->next = new_last;
        } else {
            new_last->next = new_last;
        }
        _last = new_last;
        _size++;
    }

    T dequeue() {
        if (!_last) throw std::runtime_error("empty queue.");
        auto first = _last->next;
        auto val = first->item;
        if (first == _last) {
            _last->next = nullptr; // prevent circular reference leak
            _last = nullptr;
        }
        else
            _last->next = first->next;
        _size--;
        return val;
    }

    auto begin() {
        if (_last) {
            return QueueIterator(_last->next);
        }
        return QueueIterator(nullptr);
    }

    auto end() {
        return QueueIterator(_last);
    }

};

int main() {
    using namespace std;

    cout << "Queue with Circular Linked List" << endl;

    Queue<int> q;
    cout << "IsEmpty? " << (q.empty() ? "true" : "false") << endl;
    for (size_t i = 0; i < 10; i++) {
        q.enqueue(i);
        cout << "Enqueued: " << i << " Size: " << q.size() << endl;
    }

    auto it = q.begin();
    while (it != q.end()) {
        cout << "Number: " << *it << endl;
        it++;
    }
    cout << "Number: " << *it << endl;
    it++;

    while (it != q.end()) {
        cout << "Number: " << *it << endl;
        it++;
    }
    cout << "Number: " << *it << endl;

    while (!q.empty()) {
        auto i = q.dequeue();
        cout << "Dequeued: " << i << endl;
    }
    
    return 0;
}