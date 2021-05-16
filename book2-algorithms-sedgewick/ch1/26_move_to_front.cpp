#include <iostream>
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

    void push_first(const T& item) {
        auto old_first = _first;
        auto new_first = std::make_shared<Node>();
        new_first->item = item;
        new_first->next = old_first;
        _first = new_first;
        if (empty())
            _last = _first;
        _size++;
    }

    void push_last(const T& item) {
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

    void remove(const T& item) {
        NodePtr prev_node = nullptr;
        auto current_node = _first;
        while (current_node) {
            if (current_node->item == item) {
                if (prev_node) prev_node->next = current_node->next;
                else _first = current_node->next;
                _size--;
            }
            prev_node = current_node;
            current_node = current_node->next;
        }
    }

    auto begin() {
        if (empty()) return LinkedListIterator(nullptr);
        return LinkedListIterator(_first);
    }

    auto end() {
        return LinkedListIterator(nullptr);
    }
};

template<typename T>
class MoveToFrontCache {
private:
    LinkedList<T> _cache;
public:
    MoveToFrontCache() = default;

    [[nodiscard]] size_t size() const { return _cache.size(); }

    void push(const T& item) {
        bool exists = false;
        for (auto current : _cache) {
            if (current == item) {
                exists = true;
                break;
            }
        }
        if (exists) {
            _cache.remove(item);
            _cache.push_first(item);
        } else {
            _cache.push_last(item);
        }
    }

    auto begin() {
        return _cache.begin();
    }

    auto end() {
        return _cache.end();
    }
};

int main() {
    using namespace std;

    cout << "Move-to-front Caching Strategy with Linked List." << endl;

    MoveToFrontCache<int> cache;
    for (int i = 1; i <= 10; i++) {
        cache.push(i);
        cout << "Pushing: " << i << " Size: " << cache.size() << endl;
    }

    cache.push(11);
    cache.push(5);
    cache.push(7);
    cache.push(10);
    cache.push(12);
    cache.push(13);

    cout << "Numbers: ";
    for (auto i : cache) {
        cout << i << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
