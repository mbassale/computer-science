#include <array>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T, size_t NumberOfStacks>
class MultiStack {
 public:
  MultiStack(size_t capacity) : capacity_(capacity) {
    data_.resize(capacity_ * NumberOfStacks);
    for (size_t i = 0; i < NumberOfStacks; i++) {
      topIndexes_[i] = i * capacity_;
    }
  }

  void push(size_t stackIndex, const T& item) {
    data_[topIndexes_[stackIndex]] = item;
    topIndexes_[stackIndex]++;
  }

  T pop(size_t stackIndex) {
    auto value = data_[topIndexes_[stackIndex] - 1];
    topIndexes_[stackIndex]--;
    return value;
  }

  T peek(size_t stackIndex) const { return data_[topIndexes_[stackIndex] - 1]; }

  size_t size(size_t stackIndex) const {
    return topIndexes_[stackIndex] - (stackIndex * capacity_);
  }

 private:
  size_t capacity_;
  vector<T> data_;
  array<size_t, NumberOfStacks> topIndexes_;
};

template <typename T>
void testMultiStack(const initializer_list<T>& data1,
                    const initializer_list<T>& data2,
                    const initializer_list<T>& data3) {
  MultiStack<T, 3> multiStack(10);

  auto testStack = [&](size_t stackIndex, const initializer_list<T>& data) {
    for (const auto& item : data) {
      multiStack.push(stackIndex, item);
      cout << "Stack #" << stackIndex << ": Item: " << item << " Peek: " << multiStack.peek(stackIndex)
           << " Size: " << multiStack.size(stackIndex) << endl;
    }
    vector<T> dataVector = data;
    auto it = dataVector.rbegin();
    while(it != dataVector.rend()) {
      const auto controlItem = *it;
      const auto value = multiStack.pop(stackIndex);
      cout << "Stack #" << stackIndex << ": TestItem: " << value
           << " ControlItem: " << controlItem
           << " Peek: " << multiStack.peek(stackIndex)
           << " Size: " << multiStack.size(stackIndex) << endl;
      it++;
    }
  };

  testStack(0, data1);
  testStack(1, data2);
  testStack(2, data3);
}

int main(int argc, char* argv[]) {
  testMultiStack({1, 2}, {3, 4, 5}, {6, 7, 8, 9, 10});
  return EXIT_SUCCESS;
}