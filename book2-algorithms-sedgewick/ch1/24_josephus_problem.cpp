#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

template<typename T>
class Queue {
private:
    struct Node {
        T item;
        std::shared_ptr <Node> next;
    };

    std::shared_ptr <Node> _last{};
    std::shared_ptr <Node> _first{};
    size_t _size{};

public:
    Queue() = default;

    [[nodiscard]] size_t size() { return _size; }

    [[nodiscard]] bool empty() { return _size == 0; }

    void enqueue(const T &item) {
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

int main(int argc, char *argv[]) {
    using namespace std;

    cout << "Josephus Problem\n";
    if (argc < 3) {
        cerr << "Insufficient parameters, missing M and N.\n";
        return EXIT_FAILURE;
    }

    auto M = stoi(argv[1]);
    auto N = stoi(argv[2]);

    cout << "M=" << M << " N=" << N << endl;

    Queue<int> queue;
    for (int i = 0; i < N; i++) {
        queue.enqueue(i);
        cout << "Enqueued: " << i << " Size: " << queue.size() << endl;
    }

    cout << "Order of Elimination: ";
    int index = 0;
    int next_index = index + M - 1;
    while (!queue.empty()) {
        auto num = queue.dequeue();
        if (index == next_index) {
            cout << num << " ";
            next_index += M;
        } else {
            queue.enqueue(num);
        }
        index++;
    }
    cout << endl;

    return EXIT_SUCCESS;
}
