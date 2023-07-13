#include "lc-utility.h"

void reverse(vector<int>& arr) {
  auto left = arr.begin();
  auto right = arr.end() - 1;
  while (left < right) {
    const auto tmp = *left;
    *left = *right;
    *right = tmp;
    left++;
    right--;
  }
}

vector<int> plusOne(const vector<int>& digits) {
  vector<int> result = digits;
  reverse(result);
  int carry = 1;
  auto it = result.begin();
  while (it < result.end()) {
    auto r = *it + carry;
    if (r == 10) {
      r = 0;
      carry = 1;
    } else {
      carry = 0;
    }
    *it++ = r;
  }
  if (carry > 0) {
    result.push_back(1);
  }
  reverse(result);
  return result;
}

void runTestCase(const vector<int>& digits) {
  const auto digitsStr = vector2str(digits);
  const auto start = high_resolution_clock::now();
  const auto result = plusOne(digits);
  const auto end = high_resolution_clock::now();
  const auto resultStr = vector2str(result);
  cout << digitsStr << " => " << resultStr << " "
       << nanoseconds(end - start).count() << "ns" << endl;
}

int main(int argc, char* argv[]) {
  runTestCase({1});
  runTestCase({1, 2});
  runTestCase({9});
  runTestCase({9, 9, 9});
  return EXIT_SUCCESS;
}
