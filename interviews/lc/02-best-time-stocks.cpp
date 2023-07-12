#include <iostream>
#include <optional>
#include <vector>
#include "lc-utility.h"

using std::cout;
using std::optional;
using std::vector;

/**
 * maxProfit: linear algorithm with std::optional instead of scalar flag.
 * Time: O(n) Space: O(1)
 */
int maxProfit(const vector<int>& prices) {
  int profit = 0;
  optional<int> buyIdx;
  for (size_t i = 0; i < prices.size() - 1; i++) {
    if (!buyIdx.has_value() && prices[i] < prices[i + 1]) {
      buyIdx = i;
    }
    if (buyIdx.has_value() && prices[i] > prices[i + 1]) {
      profit += prices[i] - prices[*buyIdx];
      buyIdx.reset();
    }
  }
  if (buyIdx.has_value()) {
    profit += prices.back() - prices[*buyIdx];
  }
  return profit;
}

void runTestCase(vector<int> nums) {
  cout << vector2str(nums) << " = ";
  const auto res = maxProfit(nums);
  cout << res << std::endl;
}

int main(int argc, char* argv[]) {
  runTestCase({7, 1, 5, 3, 6, 4});
  runTestCase({1, 2, 3, 4, 5});
  runTestCase({7, 6, 4, 3, 1});
  return EXIT_SUCCESS;
}