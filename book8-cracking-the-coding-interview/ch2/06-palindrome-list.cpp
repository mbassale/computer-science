#include <chrono>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stack>

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
    if (data.size() == 0) {
      return nullptr;
    }
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
size_t getListSize(NodePtr<T> head) {
  size_t listSize = 0;
  auto node = head;
  while (node) {
    listSize++;
    node = node->next;
  }
  return listSize;
}

// Time: O(N) Space: O(N/2) with N=len(lst)
template <typename T>
bool isPalindrome(NodePtr<T> lst) {
  size_t listSize = getListSize(lst);
  if (listSize <= 1) {
    return true;
  }

  bool isOdd = listSize % 2 != 0;
  size_t middleIndex = listSize / 2;
  stack<T> s;
  size_t currentIndex = 0;
  auto node = lst;
  while (node && currentIndex < middleIndex) {
    s.push(node->value);
    currentIndex++;
    node = node->next;
  }
  if (node && isOdd) {
    node = node->next;
  }

  while (node && s.size() > 0) {
    const auto value = s.top();
    if (value != node->value) {
      return false;
    }
    s.pop();
    node = node->next;
  }

  return true;
}

template <typename T>
void printList(NodePtr<T> lst) {
  cout << "{";
  auto node = lst;
  while (node) {
    cout << node->value;
    node = node->next;
    if (node) {
      cout << ",";
    }
  }
  cout << "}";
}

template <typename T>
void invokeIsPalindrome(const initializer_list<T>& data) {
  auto lst = Node<T>::make(data);
  cout << "isPalindrome(";
  printList(lst);
  cout << ") = ";
  const auto start = high_resolution_clock::now();
  const auto result = isPalindrome(lst);
  const auto stop = high_resolution_clock::now();
  cout << result
       << " Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeIsPalindrome({1});
  invokeIsPalindrome({1, 1});
  invokeIsPalindrome({1, 2, 1});
  invokeIsPalindrome({1, 2, 3, 2, 1});
  invokeIsPalindrome({1, 2, 3, 2, 2});
  invokeIsPalindrome({1, 2, 2, 1});
  invokeIsPalindrome({1, 2, 3});
  invokeIsPalindrome({1, 2});
  return EXIT_SUCCESS;
}