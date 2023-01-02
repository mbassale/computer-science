#include <chrono>
#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node {
  T value;
  shared_ptr<Node> next;

  Node(const T& value) : value(value) {}

  static shared_ptr<Node> make(const initializer_list<T>& data) {
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> prev = nullptr;
    for (const auto& datum : data) {
      if (!head) {
        head = make_shared<Node>(datum);
        prev = head;
        continue;
      }
      auto node = make_shared<Node>(datum);
      prev->next = node;
      prev = node;
    }
    return head;
  }
};

template <typename T>
using NodePtr = shared_ptr<Node<T>>;

template <typename T>
struct PartitionResult {
  NodePtr<T> left;
  NodePtr<T> right;
};

// Time: O(N) with N=len(lst) Space: O(1)
template <typename T>
PartitionResult<T> partitionList(NodePtr<T> lst, const T& value) {
  PartitionResult<T> result;

  NodePtr<T> leftHead = nullptr;
  NodePtr<T> leftPrev = nullptr;
  NodePtr<T> rightHead = nullptr;
  NodePtr<T> rightPrev = nullptr;

  auto current = lst;
  while (current) {
    auto nextNode = current->next;

    if (current->value < value) {  // put value in the left list
      if (!leftPrev) {
        leftHead = current;
        leftPrev = current;
      } else {
        // link previous node with current node
        leftPrev->next = current;
        // save current node as previous node for next iteration
        leftPrev = current;
        // the previous node could be the last in the list, so we set the next as null
        leftPrev->next = nullptr;
      }
    } else {  // put value in the right list
      if (!rightPrev) {
        rightHead = current;
        rightPrev = current;
      } else {
        rightPrev->next = current;
        rightPrev = current;
        rightPrev->next = nullptr;
      }
    }

    current = nextNode;
  }

  result.left = leftHead;
  result.right = rightHead;
  return result;
}

template <typename T>
void printList(const NodePtr<T>& lst) {
  cout << "{";
  for (auto node = lst; node;) {
    cout << node->value;
    node = node->next;
    if (node) {
      cout << ",";
    }
  }
  cout << "}";
}

template <typename T>
void invokePartitionList(const initializer_list<T>& lst, const T& value) {
  cout << "partitionList(";
  auto head = Node<T>::make(lst);
  printList(head);
  cout << ", " << value << ") = ";
  auto partitionResult = partitionList<T>(head, value);
  printList(partitionResult.left);
  cout << ",";
  printList(partitionResult.right);
  cout << endl;
}

int main(int argc, char* argv[]) {
  // {3,2,1},{5,8,5,10}
  invokePartitionList({3, 5, 8, 5, 10, 2, 1}, 5);
  // {1,2,3,4,5,6,7,8,9},{10}
  invokePartitionList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
  // {1,2,3,4,5,6,7,8,9,10},{}
  invokePartitionList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 20);
  // {},{1,2,3,4,5,6,7,8,9,10}
  invokePartitionList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0);
  // {},{1}
  invokePartitionList({1}, 1);
  // {0},{}
  invokePartitionList({0}, 1);
  return EXIT_SUCCESS;
}