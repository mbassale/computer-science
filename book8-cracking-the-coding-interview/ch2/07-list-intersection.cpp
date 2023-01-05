#include <chrono>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <unordered_map>
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

  static NodePtr<T> make(const initializer_list<T>& data) {
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

// Time: O(N) with N=len(lst) Space: O(1)
template <typename T>
pair<NodePtr<T>, size_t> findTailAndSize(NodePtr<T> lst) {
  size_t lstSize = 1;
  auto node = lst;
  while (node->next) {
    lstSize++;
    node = node->next;
  }
  return {node, lstSize};
}

// Time: O(M+N) with M=len(lst1) and N=len(lst2) Space: O(1)
template <typename T>
NodePtr<T> intersect(NodePtr<T> lst1, NodePtr<T> lst2) {
  auto tailAndSize1 = findTailAndSize(lst1);
  auto tail1 = tailAndSize1.first;
  auto size1 = tailAndSize1.second;

  auto tailAndSize2 = findTailAndSize(lst2);
  auto tail2 = tailAndSize2.first;
  auto size2 = tailAndSize2.second;

  // lists don't have same tail, so there is no intersection
  if (tail1 != tail2) {
    return nullptr;
  }

  // if list sizes are equal we just iterate in tandem until
  // we find the common node
  NodePtr<T> minList, maxList;
  size_t minSize = min(size1, size2);
  size_t maxSize = max(size1, size2);
  if (minSize == maxSize) {
    minList = lst1;
    maxList = lst2;
  } else {  // list sizes not equal, need to find min & max lists
    if (size1 < size2) {
      minList = lst1;
      maxList = lst2;
    } else {
      minList = lst2;
      maxList = lst1;
    }
    // advance maxList until have the same size as minList
    auto node = maxList;
    auto sizeDiff = maxSize - minSize;
    while (node && sizeDiff-- > 0) {
      node = node->next;
    }
    maxList = node;
  }

  // iterate in tandem to find common node by reference
  // (pointer in this case)
  auto node1 = minList;
  auto node2 = maxList;
  while (node1 && node2) {
    if (node1 == node2) {
      return node1;
    }
    node1 = node1->next;
    node2 = node2->next;
  }

  return nullptr;
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
void invokeIntersect(NodePtr<T> lst1, NodePtr<T> lst2) {
  cout << "intersect(";
  printList(lst1);
  cout << ", ";
  printList(lst2);
  cout << ") = ";
  auto start = high_resolution_clock::now();
  auto intersectNode = intersect(lst1, lst2);
  auto stop = high_resolution_clock::now();
  printList(intersectNode);
  cout << " Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char* argv[]) {
  auto prefix1 = Node<int>::make({1, 2, 3});
  auto prefix2 = Node<int>::make({0, 0, 0});
  auto suffix = Node<int>::make({4, 5, 6});
  auto tail1 = findTailAndSize(prefix1).first;
  auto tail2 = findTailAndSize(prefix2).first;
  tail1->next = suffix;
  tail2->next = suffix;
  invokeIntersect(prefix1, prefix2);

  prefix1 = Node<int>::make({0});
  prefix2 = Node<int>::make({0, 0, 0});
  suffix = Node<int>::make({1, 2, 3});
  tail1 = findTailAndSize(prefix1).first;
  tail2 = findTailAndSize(prefix2).first;
  tail1->next = suffix;
  tail2->next = suffix;
  invokeIntersect(prefix1, prefix2);

  prefix1 = Node<int>::make({0, 0, 0});
  prefix2 = Node<int>::make({0});
  suffix = Node<int>::make({1, 2, 3});
  tail1 = findTailAndSize(prefix1).first;
  tail2 = findTailAndSize(prefix2).first;
  tail1->next = suffix;
  tail2->next = suffix;
  invokeIntersect(prefix1, prefix2);
  return EXIT_SUCCESS;
}