#include <iostream>
#include <string>
#include <vector>
#include "lc-utility.h"

using std::string;
using std::vector;

void reverse(vector<int>& nums, vector<int>::iterator left,
             vector<int>::iterator right) {
  while (left < right) {
    const auto tmp = *left;
    *left = *right;
    *right = tmp;
    left++;
    right--;
  }
}

void rotate(vector<int>& nums, size_t k) {
  k = k % nums.size();
  if (k > 0) {
    reverse(nums, nums.begin(), nums.end() - 1);
    reverse(nums, nums.begin(), nums.begin() + k - 1);
    reverse(nums, nums.begin() + k, nums.end() - 1);
  }
}

void runTestCase(vector<int> nums, size_t k) {
  const auto originalArr = vector2str(nums);
  rotate(nums, k);
  const auto rotatedArr = vector2str(nums);
  std::cout << originalArr << " => " << rotatedArr << " k=" << k << std::endl;
}

int main(int argc, char* argv[]) {
  runTestCase({1}, 0);
  runTestCase({1}, 10);
  runTestCase({1, 2}, 1);
  runTestCase({1, 2}, 2);
  runTestCase({1, 2}, 3);
  runTestCase({1, 2, 3, 4, 5, 6, 7}, 3);
  return EXIT_SUCCESS;
}