#include <initializer_list>
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
    const auto value = top_->value;
    top_ = top_->next;
    size_--;
    return value;
  }

  size_t size() { return size_; }

  bool empty() { return size() == 0; }

  T& peek() const { return top_->value; }

 private:
  shared_ptr<StackNode<T>> top_;
  size_t size_;
};

// Time Complexity: O(N^2): for each element we need to re-stack that is N*N.
// Space Complexity: O(N): we need just 1 stack with N elements.
template <typename T>
class SortedStack {
 public:
  SortedStack() {}

  // O(N): we need to re-stack elements in their sorted positions to get a sorted descending stack.
  void push(const T& value) {
    if (sortedStack_.empty()) {
      sortedStack_.push(value);
      return;
    }

    bool valuePushed = false;
    Stack<T> tempStack;
    while (!sortedStack_.empty()) {
      const auto sortedValue = sortedStack_.pop();
      if (!valuePushed && sortedValue < value) {
        tempStack.push(value);
        valuePushed = true;
      }
      tempStack.push(sortedValue);
    }
    if (!valuePushed) {
      tempStack.push(value);
    }

    while (!tempStack.empty()) {
      auto value = tempStack.pop();
      sortedStack_.push(value);
    }
  }

  // O(1): the stack is already sorted.
  T pop() { return sortedStack_.pop(); }

  T& peek() { return sortedStack_.peek(); }

  size_t size() { return sortedStack_.size(); }

  bool empty() { return sortedStack_.empty(); }

 private:
  Stack<T> sortedStack_;
};

int main(int argc, char* argv[]) {
  const auto testCase = {3, 2, 6, 1, 0, 9, 10};
  SortedStack<int> sortedStack;
  for (const auto value : testCase) {
    sortedStack.push(value);
    cout << "Pushing: " << value << " Peek:" << sortedStack.peek()
         << " Size: " << sortedStack.size() << " IsEmpty? "
         << sortedStack.empty() << endl;
  }
  while (!sortedStack.empty()) {
    cout << "Poping: " << sortedStack.pop() << " Peek: "
         << (sortedStack.empty() ? "N/A" : to_string(sortedStack.peek()))
         << " Size: " << sortedStack.size() << " IsEmpty? "
         << sortedStack.empty() << endl;
  }
  return EXIT_SUCCESS;
}