#include <chrono>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

// Time: O(N) Space: O(N) with N=len(lst)
template <typename T>
void removeDuplicatesHashTable(list<T>& lst) {
  if (lst.size() < 1) {
    return;
  }
  unordered_map<T, bool> seen;
  auto it = lst.begin();
  while (it != lst.end()) {
    if (seen.find(*it) != seen.end()) {
      auto itToErase = it;
      it++;
      lst.erase(itToErase);
      continue;
    } else {
      seen[*it] = true;
    }
    it++;
  }
}

// Time: O(N^2) Space: O(1)
template<typename T>
void removeDuplicatesTwoPointers(list<T>& lst) {
  if (lst.size() < 1) {
    return;
  }

  auto it = lst.begin();
  while (it != lst.end()) {
    const auto currentIt = it;
    const auto currentValue = *it;
    it++;
    while (it != lst.end()) {
      if (*it == currentValue) {
        auto nextIt = it;
        nextIt++;
        lst.erase(it);
        it = nextIt;
        continue;
      }
      it++;
    }
    it = currentIt;
    it++;
  }
}

template <typename T>
void printList(list<T>& lst) {
  for (auto it = lst.cbegin(); it != lst.cend(); it++) {
    cout << *it << " ";
  }
}

template <typename T>
void invokeRemoveDuplicates(list<T>& lst) {
  auto l = lst;
  cout << "Before: ";
  printList(l);
  auto start = high_resolution_clock::now();
  removeDuplicatesHashTable(l);
  auto stop = high_resolution_clock::now();
  cout << endl;
  cout << "After removeDuplicatesHashTable(): ";
  printList(l);
  cout << endl;
  cout << "Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;

  l = lst;
  cout << "Before: ";
  printList(l);
  start = high_resolution_clock::now();
  removeDuplicatesTwoPointers(l);
  stop = high_resolution_clock::now();
  cout << endl;
  cout << "After removeDuplicatesTwoPointers(): ";
  printList(l);
  cout << endl;
  cout << "Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char* argv[]) {
  list<int> lst({1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10});
  invokeRemoveDuplicates(lst);
  lst = {1, 1, 1};
  invokeRemoveDuplicates(lst);
  lst = {1, 1};
  invokeRemoveDuplicates(lst);
  return EXIT_SUCCESS;
}