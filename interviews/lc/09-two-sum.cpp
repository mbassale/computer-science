#include <chrono>
#include "lc-utility.h"

pair<size_t, size_t> twoSum(const vector<int>& nums, int target) {
  unordered_map<int, size_t> seen;
  for (size_t i = 0; i < nums.size(); i++) {
    const auto diff = target - nums[i];
    if (seen.count(diff) > 0) {
      const auto idx1 = seen[diff];
      return {idx1, i};
    }
    seen[nums[i]] = i;
  }
  return {SIZE_T_MAX, SIZE_T_MAX};
}

void runTestCase(vector<int> nums, int target) {
  const auto numsStr = vector2str(nums);
  const auto start = high_resolution_clock::now();
  const auto [leftIdx, rightIdx] = twoSum(nums, target);
  const auto end = high_resolution_clock::now();
  cout << numsStr << " target: " << target << " => [" << leftIdx << ", "
       << rightIdx << "] " << (end - start).count() << "ns" << endl;
}

int main(int argc, char* argv[]) {
  runTestCase({2, 7, 11, 15}, 9);
  runTestCase({3, 2, 4}, 6);
  runTestCase({3, 3}, 6);
  return EXIT_SUCCESS;
}
