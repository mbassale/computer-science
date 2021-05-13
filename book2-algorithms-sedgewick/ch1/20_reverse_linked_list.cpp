#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

template<typename T>
class LinkedList {
private:
    struct Node {
        T item;
        std::shared_ptr<Node> next{};
    };

    typedef std::shared_ptr<Node> NodePtr;

    NodePtr _first{};
    NodePtr _last{};
    size_t _size{};

public:
    struct LinkedListIterator {
        NodePtr p;
        LinkedListIterator(const NodePtr& p) : p(p) {}
        LinkedListIterator(const LinkedListIterator& it) : p(it.p) {}
        T& operator*() { return p->item; }
        bool operator==(const LinkedListIterator& rhs) { return p == rhs.p; }
        bool operator!=(const LinkedListIterator& rhs) { return p != rhs.p; }
        LinkedListIterator& operator++() { p = p->next; return *this; }
        LinkedListIterator operator++(int) { 
            LinkedListIterator tmp(*this);
            operator++();
            return tmp;
        }
    };

    LinkedList() = default;

    [[nodiscard]] size_t size() const { return _size; }
    [[nodiscard]] bool empty() const { return size() == 0; }

    void push(const T& item) {
        auto old_last = _last;
        auto new_last = std::make_shared<Node>();
        new_last->item = item;
        _last = new_last;
        if (empty())
            _first = _last;
        else
            old_last->next = _last;
        _size++;
    }

    void reverse() {
        // 3 pointers
        NodePtr ptr1;
        NodePtr ptr2;
        NodePtr ptr3;

        ptr1 = nullptr;
        ptr2 = _first;
        ptr3 = nullptr;
        while (ptr2) {
            // reverse the pointer
            ptr3 = ptr2->next;
            ptr2->next = ptr1;

            // advance one node and reassing
            ptr1 = ptr2;
            ptr2 = ptr3;
            if (ptr3) ptr3 = ptr3->next;
        }

        NodePtr old_last = _last;
        _last = _first;
        _first = old_last;
    }

    auto begin() {
        if (empty()) return LinkedListIterator(nullptr);
        return LinkedListIterator(_first);
    }

    auto end() {
        return LinkedListIterator(nullptr);
    }
};

int main() {
    using namespace std;

    cout << "Reverse Linked List Problem." << endl;

    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push(i);
        cout << "Pushed: " << i << " Size: " << list.size() << endl;
    }

    list.reverse();

    for (auto i : list) {
        cout << "Number: " << i << endl;
    }

    return 0;
}