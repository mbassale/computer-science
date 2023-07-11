#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::vector;

int removeDuplicates(vector<int>& nums) {
  int insertionIndex = 1;
  int i = 1;
  while (insertionIndex < nums.size() && i < nums.size()) {
    while (i < nums.size() && nums[insertionIndex - 1] == nums[i]) {
      i++;
    }
    if (i < nums.size()) {
      nums[insertionIndex] = nums[i];
      insertionIndex++;
      i++;
    }
  }
  return insertionIndex;
}

string vector2str(const vector<int>& nums, size_t maxCount = SIZE_T_MAX) {
  ostringstream ss;
  int upperBound = std::min(nums.size(), maxCount);
  for (size_t i = 0; i < upperBound; i++) {
    ss << nums[i];
    if (i < upperBound - 1) {
      ss << ",";
    }
  }
  return ss.str();
}

void runTestCase(vector<int> nums) {
  cout << vector2str(nums) << " => ";
  const auto k = removeDuplicates(nums);
  cout << vector2str(nums, k) << " k=" << k << endl;
}

int main(int argc, char* argv[]) {
  runTestCase({1});
  runTestCase({1, 1});
  runTestCase({1, 1, 1, 1, 1, 1, 1, 1});
  runTestCase({1, 1, 1, 1, 1, 1, 1, 1, 1, 2});
  runTestCase({1, 2});
  runTestCase({1, 2, 2, 2, 2, 2, 2, 2});
  runTestCase({1, 2, 2, 2, 2, 2, 2, 2, 2, 3});
  runTestCase({1, 2, 3, 3, 4, 5, 5, 5, 6});
  return EXIT_SUCCESS;
}