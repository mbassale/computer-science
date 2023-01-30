#include <chrono>
#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct StackNode {
  T data;
  shared_ptr<StackNode> next;

  StackNode(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack {
 public:
  Stack() : top_(nullptr), size_(0) {}

  void push(const T& item) {
    auto newNode = make_shared<StackNode<T>>(item);
    if (top_ == nullptr) {
      top_ = newNode;
    } else {
      newNode->next = top_;
      top_ = newNode;
    }
    size_++;
  }

  T pop() {
    auto value = top_->data;
    top_ = top_->next;
    size_--;
    return value;
  }

  T& peek() const { return top_->data; }

  size_t size() const { return size_; }

  bool empty() const { return top_ == nullptr; }

 private:
  shared_ptr<StackNode<T>> top_;
  size_t size_;
};

template <typename T>
void testStack(const initializer_list<T>& itemsToPush,
               const initializer_list<T>& itemsToPop, size_t finalSize) {
  Stack<T> stack;
  for (const auto& item : itemsToPush) {
    stack.push(item);
    cout << "Pushing: " << item << " Top: " << stack.peek()
         << " Size: " << stack.size() << endl;
  }

  for (const auto& controlItem : itemsToPop) {
    const auto testItem = stack.pop();
    cout << "Popping: " << testItem << " ControlItem: " << controlItem
         << " Top: ";
    if (stack.size() > 0) {
      cout << stack.peek();
    } else {
      cout << "N/A";
    }
    cout << " Size: " << stack.size() << " IsEmpty? "
         << (stack.empty() ? "true" : "false") << endl;
  }

  cout << "Stack Size: " << stack.size() << " ControlSize: " << finalSize
       << endl;
}

int main(int argc, char* argv[]) {
  testStack({1, 2, 3}, {3, 2}, 1);
  testStack({"test1", "test2", "test3"}, {"test3", "test2", "test1"}, 0);
  testStack({0.1, 0.2, 0.3}, {0.3, 0.2, 0.1}, 0);
  return EXIT_SUCCESS;
}