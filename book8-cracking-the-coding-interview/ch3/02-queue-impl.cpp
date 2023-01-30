#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct QueueNode {
  T data;
  shared_ptr<QueueNode<T>> next;

  QueueNode(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue {
 public:
  Queue() : first_(nullptr), last_(nullptr), size_(0) {}

  void add(const T& item) {
    auto newNode = make_shared<QueueNode<T>>(item);
    if (first_ == nullptr) {
      first_ = newNode;
      last_ = first_;
    } else {
      last_->next = newNode;
      last_ = newNode;
    }
    size_++;
  }

  T remove() {
    auto value = first_->data;
    first_ = first_->next;
    if (first_ == nullptr) {
      last_ = nullptr;
    }
    size_--;
    return value;
  }

  T peek() const { return first_->data; }

  size_t size() const { return size_; }
  bool empty() const { return first_ == nullptr; }

 private:
  shared_ptr<QueueNode<T>> first_;
  shared_ptr<QueueNode<T>> last_;
  size_t size_;
};

template <typename T>
void testQueue(const initializer_list<T>& itemsToEnqueue,
               const initializer_list<T>& itemsToDequeue, size_t finalSize) {
  Queue<T> queue;
  for (const auto& item : itemsToEnqueue) {
    queue.add(item);
    cout << "Enqueue: " << item << "Peek: " << queue.peek()
         << " Size: " << queue.size() << endl;
  }

  for (const auto& controlItem : itemsToDequeue) {
    const auto testItem = queue.remove();
    cout << "Dequeue: " << testItem << " ControlItem: " << controlItem;
    cout << " Peek: ";
    if (queue.empty()) {
      cout << "N/A";
    } else {
      cout << queue.peek();
    }
    cout << " Size: " << queue.size() << " IsEmpty? "
         << (queue.empty() ? "true" : "false") << endl;
  }

  cout << "Size: " << queue.size() << " ControlSize: " << finalSize << endl;
}

int main(int argc, char* argv[]) {
  testQueue({1, 2, 3}, {1, 2}, 1);
  testQueue({"test1", "test2", "test3"}, {"test1", "test2", "test3"}, 0);
  return EXIT_SUCCESS;
}