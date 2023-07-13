#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "lc-utility.h"

using std::string;
using std::unordered_set;
using std::vector;

bool containsDuplicate(const vector<int>& nums) {
  unordered_set<int> seen;
  for (const auto n : nums) {
    if (seen.count(n) > 0) {
      return true;
    }
    seen.insert(n);
  }
  return false;
}

void runTestCase(const vector<int> nums, bool expected) {
  const auto numsStr = vector2str(nums);
  const auto actual = containsDuplicate(nums);
  std::cout << numsStr << " => Expected: " << std::to_string(expected)
            << " Actual: " << std::to_string(actual) << std::endl;
}

int main(int argc, char* argv[]) {
  runTestCase({1, 2, 3, 1}, true);
  runTestCase({1, 2, 3, 4}, false);
  runTestCase({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true);
  return EXIT_SUCCESS;
}