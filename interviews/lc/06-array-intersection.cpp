#include "lc-utility.h"

vector<int> intersectHash(const vector<int>& nums1, const vector<int>& nums2) {
  unordered_map<int, int> num1Freqs;
  for (const auto n : nums1) {
    num1Freqs[n]++;
  }
  vector<int> result;
  for (const auto n : nums2) {
    if (num1Freqs.count(n) > 0 && num1Freqs[n] > 0) {
      result.push_back(num1Freqs[n]);
      num1Freqs[n]--;
    }
  }
  return result;
}

vector<int> intersectSort(vector<int> nums1, vector<int> nums2) {
  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());
  int ptr1 = 0;
  int ptr2 = 0;
  vector<int> result;
  while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
    const auto n1 = nums1[ptr1];
    const auto n2 = nums2[ptr2];
    if (n1 == n2) {
      result.push_back(n1);
      ptr1++;
      ptr2++;
    } else if (n1 < n2) {
      ptr1++;
    } else {  // n1 > n2
      ptr2++;
    }
  }
  return result;
}

void runTestCase(const vector<int>& nums1, const vector<int>& nums2) {
  const auto nums1Str = vector2str(nums1);
  const auto nums2Str = vector2str(nums2);
  {
    const auto start = high_resolution_clock::now();
    const auto result = intersectHash(nums1, nums2);
    const auto end = high_resolution_clock::now();
    const auto resultStr = vector2str(result);
    const auto runtimeNs = nanoseconds(end - start).count();
    cout << "intersectHash: " << nums1Str << " & " << nums2Str << " => "
         << resultStr << runtimeNs << "ns" << endl;
  }
  {
    const auto start = high_resolution_clock::now();
    const auto result = intersectSort(nums1, nums2);
    const auto end = high_resolution_clock::now();
    const auto resultStr = vector2str(result);
    const auto runtimeNs = nanoseconds(end - start).count();
    cout << "intersectSort: " << nums1Str << " & " << nums2Str << " => "
         << resultStr << runtimeNs << "ns" << endl;
  }
}

int main(int argc, char* argv[]) {
  runTestCase({1, 2, 2, 1}, {2, 2});
  runTestCase({4, 9, 5}, {9, 4, 9, 8, 4});
  return EXIT_SUCCESS;
}