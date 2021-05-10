#include <iostream>
#include <string>
#include <memory>

template<typename T>
class Stack {
private:
    struct Node
    {
        T item;
        std::shared_ptr<Node> next;
    };

    std::shared_ptr<Node> _first{};
    size_t _size{};

public:
    Stack() = default;

    [[nodiscard]] bool empty() { return _size == 0; }
    [[nodiscard]] size_t size() { return _size; }

    void push(const T& item) {
        auto old_first = _first;
        auto new_first = std::make_shared<Node>();
        new_first->item = item;
        new_first->next = old_first;
        _first = new_first;
        _size++;
    }

    T pop() {
        auto popped_item = _first;
        _first = _first->next;
        _size--;
        return popped_item->item;
    }

};

int main() {
    using namespace std;

    cout << "LinkedList Push Down Stack Implementation" << endl;

    Stack<int> s{};
    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        s.push(i);
        cout << "Pushed: " << i << " Size: " << s.size() << endl;
    }
    
    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    for (size_t i = 0; i < 100; i++) {
        cout << "Popped: " << s.pop() << " Size: " << s.size() << endl;
    }

    cout << "IsEmpty? " << (s.empty() ? "true" : "false") << endl;

    return 0;
}
