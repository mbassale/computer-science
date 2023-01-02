#include <chrono>
#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;
using namespace std::chrono;

template <typename T>
struct Node {
  T value;
  shared_ptr<Node<T>> next;

  Node(const T& value) : value(value) {}

  static shared_ptr<Node<T>> make(const initializer_list<T>& data) {
    if (data.size() == 0) {
      return nullptr;
    }
    auto it = data.begin();
    auto head = make_shared<Node<T>>(*it);
    auto prev = head;
    it++;
    while (it != data.end()) {
      auto node = make_shared<Node<T>>(*it);
      prev->next = node;
      prev = node;
      it++;
    }
    return head;
  }
};

template <typename T>
using NodePtr = shared_ptr<Node<T>>;

// Time: O(max(M,N)) Space: O(max(M,N)) with M=len(lst1) and N=len(lst2)
template <typename T>
NodePtr<T> sumLists(NodePtr<T> head1, NodePtr<T> head2) {
  if (!head1 || !head2) {
    return nullptr;
  }
  NodePtr<T> newHead;
  NodePtr<T> prev;
  auto node1 = head1;
  auto node2 = head2;
  T carry = 0;
  while (node1 && node2) {
    const auto& value1 = node1->value;
    const auto& value2 = node2->value;
    const auto sum = value1 + value2 + carry;
    auto newNode = make_shared<Node<T>>(sum % 10);
    carry = sum > 9 ? 1 : 0;
    if (!newHead) {
      newHead = newNode;
      prev = newHead;
    } else {
      prev->next = newNode;
      prev = newNode;
    }
    node1 = node1->next;
    node2 = node2->next;
  }

  while (node1) {
    const auto& value1 = node1->value;
    const auto sum = value1 + carry;
    auto newNode = make_shared<Node<T>>(sum % 10);
    carry = sum > 9 ? 1 : 0;
    prev->next = newNode;
    prev = newNode;
    node1 = node1->next;
  }

  while (node2) {
    const auto& value2 = node2->value;
    const auto sum = value2 + carry;
    auto newNode = make_shared<Node<T>>(sum % 10);
    carry = sum > 9 ? 1 : 0;
    prev->next = newNode;
    prev = newNode;
    node2 = node2->next;
  }

  if (carry) {
    auto newNode = make_shared<Node<T>>(1);
    prev->next = newNode;
  }

  return newHead;
}

template <typename T>
void printList(NodePtr<T> head) {
  auto node = head;
  cout << "{";
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
void invokeSumLists(const initializer_list<T>& data1,
                    const initializer_list<T>& data2) {
  auto lst1 = Node<T>::make(data1);
  auto lst2 = Node<T>::make(data2);
  cout << "sumLists(";
  printList(lst1);
  cout << ",";
  printList(lst2);
  cout << ") = ";
  const auto start = high_resolution_clock::now();
  auto result = sumLists(lst1, lst2);
  const auto stop = high_resolution_clock::now();
  printList(result);
  cout << " Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char* argv[]) {
  invokeSumLists({7, 1, 6}, {5, 9, 2});
  invokeSumLists({9, 9, 9}, {9, 9, 9});
  invokeSumLists({9, 9}, {1});
  invokeSumLists({1}, {9, 9});
  invokeSumLists({9LL, 9LL, 9LL}, {9LL, 9LL, 9LL});
  invokeSumLists<uint16_t>({9, 9, 9}, {9, 9, 9});
  return EXIT_SUCCESS;
}