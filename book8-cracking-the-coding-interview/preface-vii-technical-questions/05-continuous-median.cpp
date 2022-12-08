#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

class ContinuousMedian {
 public:
  ContinuousMedian() = default;

  // Time: O(n) Space: O(n)
  void push(int value) {
    minHeap.push_back(value);
    push_heap(minHeap.begin(), minHeap.end() - 1,
              [](const auto& a, const auto& b) { return a >= b; });
    maxHeap.push_back(value);
    push_heap(maxHeap.begin(), maxHeap.end() - 1,
              [](const auto& a, const auto& b) { return a < b; });
  }

  double get_min() {
    if (!minHeap.empty()) {
      return minHeap.front();
    }
    return 0;
  }

  double get_max() {
    if (!maxHeap.empty()) {
      return maxHeap.front();
    }
    return 0;
  }

  double get_median() {
    if (minHeap.size() > 0 && maxHeap.size() > 0) {
      const auto minVal = minHeap.front();
      const auto maxVal = maxHeap.front();
      return (minVal + maxVal) / 2.0;
    }
    return 0;
  }

 protected:
  vector<int> minHeap;
  vector<int> maxHeap;
};

void executeContinuousMedian(const vector<int>& testCase) {
  const auto start = high_resolution_clock::now();
  ContinuousMedian continuousMedian;
  for (const auto testVal : testCase) {
    continuousMedian.push(testVal);
    const auto minVal = continuousMedian.get_min();
    const auto maxVal = continuousMedian.get_max();
    const auto median = continuousMedian.get_median();
    cout << "Pushing: " << testVal << " Min: " << minVal << " Max: " << maxVal
         << " Median: " << median << endl;
  }
  const auto stop = high_resolution_clock::now();
  cout << "Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;
}

int main(int argc, char* argv[]) {
  executeContinuousMedian({2, 3, 4, 5, 6, 7, 2, 4, 5, 6, 4});
  executeContinuousMedian({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  return EXIT_SUCCESS;
}