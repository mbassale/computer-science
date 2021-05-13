#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
class Deque {
private:
    struct Node;
    typedef std::shared_ptr<Node> NodePtr;

    struct Node {
        T item;
        NodePtr prev;
        NodePtr next;
    };

    NodePtr _left;
    NodePtr _right;
    size_t _size{};

public:
    struct DequeIterator {
        std::shared_ptr<Node> p;
        DequeIterator(const std::shared_ptr<Node>& p) : p(p) {}
        DequeIterator(const DequeIterator& it) : p(it.p) {}
        T& operator*() { return p->item; }
        bool operator==(const DequeIterator& rhs) { return p == rhs.p; }
        bool operator!=(const DequeIterator& rhs) { return p != rhs.p; }
        DequeIterator& operator++() { p = p->next; return *this; }
        DequeIterator operator++(int) { 
            DequeIterator tmp(*this);
            operator++();
            return tmp;
        }
    };

    Deque() = default;
    ~Deque() = default;

    [[nodiscard]] size_t size() const { return _size; }
    [[nodiscard]] bool empty() const { return _size == 0; }

    void push_left(const T& item) {
        auto old_left = _left;
        auto new_left = create_node(item);
        new_left->next = old_left;
        if (old_left) old_left->prev = new_left;
        _left = new_left;
        if (empty()) _right = _left;
        _size++;
    }

    void push_right(const T& item) {
        auto old_right = _right;
        auto new_right = create_node(item);
        new_right->prev = old_right;
        if (old_right) old_right->next = new_right;
        _right = new_right;
        if (empty()) _left = _right;
        _size++;
    }

    T pop_left() {
        if (empty()) throw std::runtime_error("Empty deque.");
        auto val = _left->item;
        auto old_left = _left;
        _left = _left->next;
        if (_left) _left->prev = nullptr;
        _size--;
        if (empty()) _right = _left;
        return val;
    }

    T pop_right() {
        if (empty()) throw std::runtime_error("Empty deque.");
        auto val = _right->item;
        _right = _right->prev;
        if (_right) _right->next = nullptr;
        _size--;
        if (empty()) _left = _right;
        return val;
    }

    auto begin() {
        if (empty()) return DequeIterator(nullptr);
        return DequeIterator(_left);
    }

    auto end() {
        return DequeIterator(nullptr);
    }

private:
    NodePtr create_node(const T& item) {
        auto node = std::make_shared<Node>();
        node->item = item;
        return node;
    }
};

int main() {
    using namespace std;

    cout << "Deque with Double Linked List" << endl;

    Deque<int> deque;

    cout << "IsEmpty? " << (deque.empty() ? "true" : "false") << endl;

    for (int i = 10; i >= 1; i--) {
        deque.push_left(i);
        cout << "PushLeft: " << i << " Size: " << deque.size() << endl;
    }

    for (int i = 11; i <= 20; i++) {
        deque.push_right(i);
        cout << "PushRight: " << i << " Size: " << deque.size() << endl;
    }

    cout << "Numbers: ";
    for (int i : deque) {
        cout << i << " ";
    }
    cout << endl;

    while (deque.size() > 10) {
        cout << "PopLeft: " << deque.pop_left() << " Size: " << deque.size() << endl;
    }

    cout << "Numbers: ";
    for (int i : deque) {
        cout << i << " ";
    }
    cout << endl;

    while (deque.size()) {
        cout << "PopRight: " << deque.pop_right() << " Size: " << deque.size() << endl;
    }

    cout << "IsEmpty? " << (deque.empty() ? "true" : "false") << endl;

    return 0;
}