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

template <typename T>
class Queue {
 public:
  Queue() {}

  // O(1): we choose fast enqueue of new elements
  void enqueue(const T& value) { 
    stack_.push(value); 
  }

  // O(n): re-push all elements into a temporary stack
  T dequeue() { 
    Stack<T> tempStack; 
    while (!stack_.empty()) {
      const auto value = stack_.pop();
      tempStack.push(value);
    }
    auto front = tempStack.pop();
    while (!tempStack.empty()) {
      const auto value = tempStack.pop();
      stack_.push(value);
    }
    return front;
  }

  size_t size() { return stack_.size(); }

  bool empty() { return stack_.empty(); }

 private:
  Stack<T> stack_;
};

int main(int argc, char* argv[]) {

  Queue<int> queue;
  for (size_t i = 0; i < 10; i++) {
    cout << "Enqueue: " << i << " Size: " << queue.size() << " IsEmpty? "
         << (queue.empty() ? "Yes" : "No") << endl;
    queue.enqueue(i);
  }

  while(!queue.empty()) {
    cout << "Dequeue: " << queue.dequeue() << " Size: " << queue.size()
         << " IsEmpty? " << (queue.empty() ? "Yes" : "No") << endl;
  }

  return EXIT_SUCCESS;
}