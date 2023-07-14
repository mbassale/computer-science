#include "lc-utility.h"

void moveZeroes(vector<int>& nums) {
  size_t nextInsertionIdx = 0;
  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      const auto tmp = nums[nextInsertionIdx];
      nums[nextInsertionIdx] = nums[i];
      nums[i] = tmp;
      nextInsertionIdx++;
    }
  }
}

void runTestCase(vector<int> nums) {
  const auto numsStr = vector2str(nums);
  moveZeroes(nums);
  const auto resultStr = vector2str(nums);
  cout << numsStr << " => " << resultStr << endl;
}

int main(int argc, char* argv[]) {
  runTestCase({0, 1, 0, 3, 12});
  runTestCase({0});
  return EXIT_SUCCESS;
}
