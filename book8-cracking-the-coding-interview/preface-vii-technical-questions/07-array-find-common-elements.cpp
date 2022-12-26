#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

// Time: O(N*log(N)) Space: O(1)
template <typename T>
size_t countElementsInCommonBinarySearch(const vector<T>& a,
                                         const vector<T>& b) {
  size_t count = 0;
  for (const auto& elem : a) {
    if (binary_search(b.begin(), b.end(), elem)) {
      count++;
    }
  }
  return count;
}

// Time: O(N) Space: O(N)
template <typename T>
size_t countElementsInCommonHashTable(const vector<T>& a, const vector<T>& b) {
  size_t count = 0;
  unordered_map<T, bool> aMap;
  for (const auto& elem : a) {
    aMap[elem] = true;
  }

  for (const auto& elem : b) {
    if (aMap.find(elem) != aMap.end()) {
      count++;
    }
  }

  return count;
}

template <typename T>
void invokeCountElementsInCommon(const vector<T>& a, const vector<T>& b) {
  auto start = high_resolution_clock::now();
  auto count = countElementsInCommonBinarySearch(a, b);
  auto stop = high_resolution_clock::now();
  auto delta = duration_cast<microseconds>(stop - start);
  cout << "countElementsInCommonBinarySearch(): " << count
       << " Runtime: " << delta.count() << "us" << endl;

  start = high_resolution_clock::now();
  count = countElementsInCommonHashTable(a, b);
  stop = high_resolution_clock::now();
  delta = duration_cast<microseconds>(stop - start);
  cout << "countElementsInCommonHashTable(): " << count
       << " Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeCountElementsInCommon<int>({13, 27, 35, 40, 49, 55, 59},
                                   {17, 35, 39, 40, 55, 58, 60});

  invokeCountElementsInCommon<int>({10, 27, 35, 40, 49, 55, 59},
                                   {1, 10, 35, 40, 55, 58, 60});
  return EXIT_SUCCESS;
}