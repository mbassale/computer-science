#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct StackNode {
  T value;
  shared_ptr<StackNode<T>> next;
  StackNode(const T& value) : value(value), next(nullptr) {}
};

template <typename T>
class Stack {
 private:
  shared_ptr<StackNode<T>> top_;
  size_t size_;

 public:
  Stack() : top_(nullptr), size_(0) {}

  void push(const T& value) {
    auto newNode = make_shared<StackNode<T>>(value);
    if (top_ == nullptr) {
      top_ = newNode;
    } else {
      newNode->next = top_;
      top_ = newNode;
    }
    size_++;
  }

  T pop() {
    auto value = top_->value;
    top_ = top_->next;
    size_--;
    return value;
  }

  T& peek() const { return top_->value; }

  bool empty() { return top_ == nullptr; }
  size_t size() { return size_; }
};

template <typename T>
class StackSet {
 private:
  Stack<Stack<T>> stacks_;
  size_t maxStackSize_;

 public:
  StackSet(size_t maxStackSize) : stacks_(), maxStackSize_(maxStackSize) {}

  void push(const T& value) {
    if (stacks_.empty()) {
      stacks_.push(Stack<T>());
    }
    if (stacks_.peek().size() == maxStackSize_) {
      stacks_.push(Stack<T>());
    }
    stacks_.peek().push(value);
  }

  T pop() {
    auto value = stacks_.peek().pop();
    if (stacks_.peek().empty()) {
      stacks_.pop();
    }
    return value;
  }

  size_t empty() { return stacks_.empty(); }

  size_t size() {
    if (empty()) {
      return 0;
    }
    return (stacks_.size() - 1) * maxStackSize_ + stacks_.peek().size();
  }

  size_t stackCount() { return stacks_.size(); }
};

int main(int argc, char* argv[]) {
  StackSet<int> stackSet(3);
  for (size_t i = 0; i < 5; i++) {
    cout << "Pushing: " << i << " Size: " << stackSet.size() << " IsEmpty? "
         << stackSet.empty() << " StacksCount: " << stackSet.stackCount()
         << endl;
    stackSet.push(i);
  }
  for (size_t i = 0; i < 5; i++) {
    cout << "Value: " << stackSet.pop() << " Size: " << stackSet.size()
         << " IsEmpty? " << stackSet.empty()
         << " StacksCount: " << stackSet.stackCount() << endl;
  }
  return EXIT_SUCCESS;
}