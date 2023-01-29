#include <chrono>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>

using namespace std;
using namespace std::chrono;

template <typename T>
struct Node;

template <typename T>
using NodePtr = shared_ptr<Node<T>>;

template <typename T>
struct Node {
  T value;
  NodePtr<T> next;

  Node(const T& value) : value(value) {}

  static NodePtr<T> make(const T& value) { return make_shared<Node<T>>(value); }

  static NodePtr<T> make(const initializer_list<T>& data) {
    auto it = data.begin();
    auto head = make(*it);
    auto prev = head;
    it++;
    while (it != data.end()) {
      auto node = make(*it);
      prev->next = node;
      prev = node;
      it++;
    }
    return head;
  }
};

template <typename T>
NodePtr<T> findTail(NodePtr<T> node) {
  while (node->next) {
    node = node->next;
  }
  return node;
}

// Time: O(N) with N=len(head) Space: O(1)
template <typename T>
NodePtr<T> findLoop(NodePtr<T> head) {
  auto slowPtr = head;
  auto fastPtr = head;
  while (slowPtr && fastPtr) {
    slowPtr = slowPtr->next;
    if (!fastPtr->next) {
      return nullptr;
    }
    fastPtr = fastPtr->next->next;
    if (slowPtr == fastPtr) {
      auto node = head;
      while (node != slowPtr) {
        node = node->next;
        slowPtr = slowPtr->next;
      }
      return slowPtr;
    }
  }
  return nullptr;
}

template <typename T>
void printList(NodePtr<T> head, size_t loopIndex, size_t printSize) {
  auto node = head;
  cout << '{';
  while (node && printSize-- > 0) {
    if (loopIndex == 0) {
      cout << '|';
    }
    cout << node->value;
    if (loopIndex == 0) {
      cout << '|';
    }
    loopIndex--;
    node = node->next;
    if (node && printSize > 0) {
      cout << ',';
    }
  }
  cout << '}';
}

template <typename T>
struct TestCase {
  NodePtr<T> head;
  size_t loopIndex;
  size_t printSize;
};

template <typename T>
void invokeFindLoop(TestCase<T>& testCase) {
  cout << "findLoop(";
  printList(testCase.head, testCase.loopIndex, testCase.printSize);
  cout << ") = ";
  auto result = findLoop(testCase.head);
  cout << (result ? to_string(result->value) : "N/A") << endl;
}

template <typename T>
TestCase<T> makeListWithLoop(const initializer_list<T>& prefixList,
                             const initializer_list<T>& suffixList) {
  auto head = Node<int>::make(prefixList);
  auto tail = findTail(head);
  auto suffix = Node<int>::make(suffixList);
  auto suffixTail = findTail(suffix);
  suffixTail->next = tail;
  tail->next = suffix;
  return TestCase<T>(
      {head, prefixList.size() - 1, prefixList.size() + suffixList.size()});
}

int main(int argc, char* argv[]) {

  auto testCase1 = makeListWithLoop({1, 2, 3}, {4, 5, 6});
  invokeFindLoop(testCase1);

  auto testCase2 = makeListWithLoop({1}, {2, 3, 4, 5, 6});
  invokeFindLoop(testCase2);

  auto testCase3 = makeListWithLoop({1, 2, 3, 4, 5}, {6});
  invokeFindLoop(testCase3);

  auto testCase4 = makeListWithLoop({1}, {2});
  invokeFindLoop(testCase4);

  return EXIT_SUCCESS;
}