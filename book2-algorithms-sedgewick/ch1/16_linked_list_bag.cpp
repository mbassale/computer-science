#include <iostream>
#include <string>
#include <memory>

template<typename T>
class Bag {
private:
    struct Node {
        T item;
        std::shared_ptr<Node> next;
    };

    std::shared_ptr<Node> _first{ nullptr };

public:
    struct BagIterator {
        std::shared_ptr<Node> p;
        BagIterator(const std::shared_ptr<Node>& p) : p(p) {}
        BagIterator(const BagIterator& it) : p(it.p) {}
        T& operator*() { return p->item; }
        bool operator==(const BagIterator& rhs) { return p == rhs.p; }
        bool operator!=(const BagIterator& rhs) { return p != rhs.p; }
        BagIterator& operator++() { p = p->next; return *this; }
        BagIterator operator++(int) { 
            BagIterator tmp(*this);
            operator++();
            return tmp;
        }
    };

    Bag() = default;

    void add(const T& item) {
        auto old_first = _first;
        auto new_first = std::make_shared<Node>();
        new_first->item = item;
        new_first->next = old_first;
        _first = new_first;
    }

    BagIterator begin() {
        return BagIterator(_first);
    }

    BagIterator end() {
        return BagIterator(nullptr);
    }
};

int main() {
    using namespace std;

    cout << "Linked List Bag Implementation" << endl;
    Bag<int> bag;
    for (size_t i = 0; i < 100; i++) {
        bag.add(i);
        cout << "Added: " << i << endl;
    }

    for (auto i : bag) {
        cout << "Number: " << i << endl;
    }
    
    return 0;
}