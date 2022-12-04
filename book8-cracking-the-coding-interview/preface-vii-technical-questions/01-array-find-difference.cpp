#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;
using namespace std::chrono;

// Time: O(n^2) Space: O(1)
int countNumberOfPairsBruteForce(vector<int>& array, int k) {
  int numberOfPairs = 0;
  for (size_t i = 0; i < array.size(); i++) {
    for (size_t j = i + 1; j < array.size(); j++) {
      if (std::abs(array[i] - array[j]) == k) {
        numberOfPairs++;
      }
    }
  }
  return numberOfPairs;
}

// Time: O(log(n)) Space: O(log(n))
optional<int> binarySearch(vector<int>& array, int num, int min, int max) {
  if (max < min) {
    return nullopt;
  }
  int mid = min + (max - min) / 2;
  const auto current = array[mid];
  if (current == num) {
    return num;
  } else if (num < current) {
    return binarySearch(array, num, min, mid - 1);
  } else {
    return binarySearch(array, num, mid + 1, max);
  }
}

// Time: O(n * log(n)) Space: O(log(n))
int countNumberOfPairs(vector<int>& array, int k) {
  sort(array.begin(), array.end());
  int numberOfPairs = 0;
  for (size_t i = 0; i < array.size(); i++) {
    const auto num = array[i];
    const auto val1 = binarySearch(array, num - k, 0, array.size() - 1);
    if (val1.has_value()) {
      numberOfPairs++;
    }
    const auto val2 = binarySearch(array, num + k, 0, array.size() - 1);
    if (val2.has_value()) {
      numberOfPairs++;
    }
  }
  return numberOfPairs / 2;
}

int main(int argc, char* argv[]) {
  // Brute Force
  vector<int> arr = {1, 7, 5, 9, 2, 12, 3};
  auto start = high_resolution_clock::now();
  auto result = countNumberOfPairsBruteForce(arr, 2);
  auto stop = high_resolution_clock::now();
  auto delta = duration_cast<nanoseconds>(stop - start);
  cout << "countNumberOfPairs(%) = " << result << " Runtime: " << delta.count()
       << "ns" << endl;

  // Sorting + Binary Search
  start = high_resolution_clock::now();
  result = countNumberOfPairs(arr, 2);
  stop = high_resolution_clock::now();
  delta = duration_cast<nanoseconds>(stop - start);
  cout << "countNumberOfPairs(%) = " << result << " Runtime: " << delta.count()
       << "ns" << endl;
  return EXIT_SUCCESS;
}