#include <iostream>
#include <list>
#include <optional>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Time: O(N) with N=len(lst) Space: O(1)
template<typename T>
optional<T> findKthToLast(const list<T>& lst, size_t k) {
  if (lst.size() == 0) {
    return nullopt;
  }

  if (k > lst.size()) {
    k = k % lst.size();
  }

  auto firstIt = lst.cbegin();

  auto secondIt = firstIt;
  while (secondIt != lst.cend() && k-- > 0) {
    secondIt++;
  }

  if (secondIt == lst.cend()) {
    return *firstIt;
  }

  while (firstIt != lst.cend() && secondIt != lst.cend()) {
    firstIt++;
    secondIt++;
  }

  if (firstIt != lst.cend()) {
    return *firstIt;
  }
  return nullopt;
}

template<typename T>
void printList(const list<T>& lst) {
  cout << "{";
  for (auto it = lst.cbegin(); it != lst.cend();) {
    cout << *it;
    it++;
    if (it != lst.cend()) {
      cout << ",";
    }
  }
  cout << "}";
}

template<typename T>
void invokeFindKthToLast(const list<T>& lst, size_t k) {
  cout << "findKthToLast(";
  printList(lst);
  cout << ", " << k << ") = ";
  const auto start = high_resolution_clock::now();
  const auto result = findKthToLast(lst, k);
  const auto stop = high_resolution_clock::now();
  cout << (result.has_value() ? to_string(*result) : "N/A")
       << " Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char *argv[]) {
  list<int> lst({1, 2, 3, 4, 5});
  invokeFindKthToLast(lst, 3);
  lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
  invokeFindKthToLast(lst, 6);
  lst = {1};
  invokeFindKthToLast(lst, 1);
  lst = {};
  invokeFindKthToLast(lst, 10);
  lst = {1, 2};
  invokeFindKthToLast(lst, 3);
  invokeFindKthToLast(lst, 2);
  return EXIT_SUCCESS;
}