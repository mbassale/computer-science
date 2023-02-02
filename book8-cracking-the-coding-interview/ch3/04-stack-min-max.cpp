#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
struct StackNode {
  T value;
  T minValue;
  T maxValue;
  shared_ptr<StackNode<T>> next;
  StackNode(const T& value, const T& minValue, const T& maxValue)
      : value(value), minValue(minValue), maxValue(maxValue), next(nullptr) {}
};

template <typename T>
class MinMaxStack {
 public:
  MinMaxStack() : first_(nullptr), size_(0) {}

  void push(const T& value) {
    auto minValue = first_ ? std::min(first_->minValue, value) : value;
    auto maxValue = first_ ? std::max(first_->maxValue, value) : value;
    auto newNode = make_shared<StackNode<T>>(value, minValue, maxValue);
    if (first_ == nullptr) {
      first_ = newNode;
    } else {
      newNode->next = first_;
      first_ = newNode;
    }
    size_++;
  }

  T pop() {
    auto value = first_->value;
    first_ = first_->next;
    size_--;
    return value;
  }

  const T& min() const { return first_->minValue; }

  const T& max() const { return first_->maxValue; }

  size_t size() const { return size_; }

  bool empty() const { return first_ == nullptr; }

 private:
  shared_ptr<StackNode<T>> first_;
  size_t size_;
};

template <typename T>
void testMinMaxStack(const initializer_list<T>& data) {
  MinMaxStack<T> minMaxStack;

  cout << "Push" << endl;
  for (const auto& value : data) {
    minMaxStack.push(value);
    cout << "Value: " << value << " Min: " << minMaxStack.min()
         << " Max: " << minMaxStack.max() << " Size: " << minMaxStack.size()
         << " IsEmpty? " << minMaxStack.empty() << endl;
  }

  cout << endl << "Pop" << endl;
  auto dataVector = vector<T>(data);
  auto it = dataVector.rbegin();
  while (it != dataVector.rend()) {
    auto value = minMaxStack.pop();
    cout << "Value:" << value << " Min: "
         << (minMaxStack.empty() ? "N/A" : to_string(minMaxStack.min()))
         << " Max: "
         << (minMaxStack.empty() ? "N/A" : to_string(minMaxStack.max()))
         << " Size: " << minMaxStack.size() << " IsEmpty? "
         << minMaxStack.empty() << endl;
    it++;
  }

  cout << endl;
}

int main(int argc, char* argv[]) {
  testMinMaxStack({1, 2, 3, 4, 5});
  testMinMaxStack({1, 4, 2, 5, 3, 0});
  return EXIT_SUCCESS;
}