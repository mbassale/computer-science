#include <iostream>
#include <unordered_set>
#include <vector>
#include "lc-utility.h"

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::chrono::high_resolution_clock;

int singleNumberHash(const vector<int>& nums) {
  unordered_map<int, size_t> numberFreqs;
  for (const auto n : nums) {
    numberFreqs[n]++;
  }
  for (const auto& p : numberFreqs) {
    if (p.second == 1) {
      return p.first;
    }
  }
  assert(false && "Unreachable");
}

int singleNumberMath(const vector<int>& nums) {
  int sumSet = 0;
  unordered_set<int> numSet(nums.begin(), nums.end());
  for (const auto n : numSet) {
    sumSet += n;
  }
  int sum = 0;
  for (const auto n : nums) {
    sum += n;
  }
  return 2 * sumSet - sum;
}

int singleNumberXor(const vector<int>& nums) {
  int result = 0;
  for (const auto n : nums) {
    result ^= n;
  }
  return result;
}

void runTestCase(const vector<int>& nums, int expected) {
  const auto numsStr = vector2str(nums);
  {
    const auto start = high_resolution_clock::now();
    const auto result = singleNumberHash(nums);
    const auto end = high_resolution_clock::now();
    std::cout << "singleNumberHash: " << numsStr << " Actual: " << result
              << " Expected: " << expected << " "
              << std::chrono::nanoseconds(end - start).count() << "ns"
              << std::endl;
  }
  {
    const auto start = high_resolution_clock::now();
    const auto result = singleNumberMath(nums);
    const auto end = high_resolution_clock::now();
    std::cout << "singleNumberMath: " << numsStr << " Actual: " << result
              << " Expected: " << expected << " "
              << std::chrono::nanoseconds(end - start).count() << "ns"
              << std::endl;
  }
  {
    const auto start = high_resolution_clock::now();
    const auto result = singleNumberXor(nums);
    const auto end = high_resolution_clock::now();
    std::cout << "singleNumberXor: " << numsStr << " Actual: " << result
              << " Expected: " << expected << " "
              << std::chrono::nanoseconds(end - start).count() << "ns"
              << std::endl;
  }
}

int main(int argc, char* argv[]) {
  runTestCase({2, 2, 1}, 1);
  runTestCase({4, 1, 2, 1, 2}, 4);
  runTestCase({1}, 1);
  runTestCase({1, 2, 3, 1, 2, 3, 4}, 4);
  return EXIT_SUCCESS;
}