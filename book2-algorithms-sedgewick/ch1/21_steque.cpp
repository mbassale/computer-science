#include <iostream>
#include <string>
#include <memory>

template<typename T>
class Steque {
private:
    struct Node {
        T item;
        std::shared_ptr<Node> next{};
    };
    typedef std::shared_ptr<Node> NodePtr;

    NodePtr _top{};
    NodePtr _bottom{};
    size_t _size{};

public:
    struct StequeIterator {
        NodePtr p;
        StequeIterator(const NodePtr& p) : p(p) {}
        StequeIterator(const StequeIterator& it) : p(it.p) {}
        T& operator*() { return p->item; }
        bool operator==(const StequeIterator& rhs) { return p == rhs.p; }
        bool operator!=(const StequeIterator& rhs) { return p != rhs.p; }
        StequeIterator& operator++() { p = p->next; return *this; }
        StequeIterator operator++(int) { 
            StequeIterator tmp(*this);
            operator++();
            return tmp;
        }
    };

    Steque() = default;

    [[nodiscard]] size_t size() const { return _size; }
    [[nodiscard]] bool empty() const { return size() == 0; }

    void enqueue(const T& item) {
        auto new_bottom = create_node(item);
        if (_bottom) _bottom->next = new_bottom;
        _bottom = new_bottom;
        if (empty()) _top = _bottom;
        _size++;
    }

    void push(const T& item) {
        auto new_top = create_node(item);
        new_top->next = _top;
        _top = new_top;
        if (empty()) _bottom = _top;
        _size++;
    }

    T pop() {
        if (empty()) throw std::runtime_error("empty stack");
        auto val = _top->item;
        _top = _top->next;
        _size--;
        if (empty()) _bottom = _top;
        return val;
    }

    auto begin() {
        if (empty()) return StequeIterator(nullptr);
        return StequeIterator(_top);
    }

    auto end() {
        return StequeIterator(nullptr);
    }

private:
    NodePtr create_node(const T& item) {
        auto new_node = std::make_shared<Node>();
        new_node->item = item;
        return new_node;
    }
};

int main() {
    using namespace std;

    cout << "Steque with Single Linked List" << endl;

    Steque<int> steque;
    cout << "IsEmpty? " << (steque.empty() ? "true" : "false") << endl;

    for (int i = 9; i >= 0; i--) {
        steque.push(i);
        cout << "Pushed: " << i << " Size: " << steque.size() << endl;
    }
    
    cout << "Numbers: ";
    for (auto i : steque) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 10; i < 20; i++) {
        steque.enqueue(i);
        cout << "Enqueued: " << i << " Size: " << steque.size() << endl;
    }

    cout << "Numbers: ";
    for (auto i : steque) {
        cout << i << " ";
    }
    cout << endl;

    while(steque.size() > 10) {
        cout << "Popped: " << steque.pop() << " Size: " << steque.size() << endl;
    }

    cout << "Numbers: ";
    for (auto i : steque) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}