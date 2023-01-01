#include <chrono>
#include <iostream>
#include <memory>

using namespace std;
using namespace std::chrono;

template <typename T>
struct Node {
  T value;
  shared_ptr<Node> next;

  Node(const T& val, shared_ptr<Node> next = nullptr)
      : value(val), next(next) {}

  static shared_ptr<Node> make(initializer_list<T> values) {
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> prev = nullptr;
    for (const auto& val : values) {
      if (!prev) {
        head = make_shared<Node>(val);
        prev = head;
      } else {
        auto node = make_shared<Node>(val);
        prev->next = node;
        prev = node;
      }
    }
    return head;
  }
};

template <typename T>
void deleteMiddleNode(const shared_ptr<Node<T>>& node) {
  if (!node || !node->next) {
    return;
  }
  node->value = node->next->value;
  node->next = node->next->next;
}

template <typename T>
void printList(const shared_ptr<Node<T>>& head) {
  auto node = head;
  cout << "{";
  while (node) {
    cout << node->value;
    node = node->next;
    if (node != nullptr) {
      cout << ",";
    }
  }
  cout << "}";
}

template <typename T>
void invokeDeleteMiddleNode(initializer_list<T> testCase, int k) {
  auto head = Node<T>::make(testCase);
  cout << "deleteMiddleNode(";
  printList(head);
  cout << ", " << k << ") = ";
  auto node = head;
  while (node && k-- > 0) {
    node = node->next;
  }
  if (k > 0) {
    cout << "Invalid value for k" << endl;
    return;
  }
  const auto start = high_resolution_clock::now();
  deleteMiddleNode(node);
  const auto stop = high_resolution_clock::now();
  printList(head);
  cout << " Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char* argv[]) {
  invokeDeleteMiddleNode({1, 2, 3, 4, 5}, 2);
  invokeDeleteMiddleNode({1, 2, 3}, 1);
  invokeDeleteMiddleNode({1, 2}, 2);
  invokeDeleteMiddleNode({1}, 3);
  return EXIT_SUCCESS;
}