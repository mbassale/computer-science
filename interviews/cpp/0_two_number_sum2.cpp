#include <iostream>
#include <vector>
#include <unordered_set>
#include <optional>

using namespace std;

std::optional<std::pair<int, int>> twoNumberSum(vector<int> array, int targetSum)
{
  sort(array.begin(), array.end());
  auto left = array.begin();
  auto right = array.end() - 1;
  while (left != right)
  {
    const auto currentSum = *left + *right;
    if (currentSum == targetSum)
    {
      return std::optional<pair<int, int>>({*left, *right});
    }
    else if (currentSum < targetSum)
    {
      left++;
    }
    else if (currentSum > targetSum)
    {
      right++;
    }
  }
  return {};
}

int main(int argc, char *argv[])
{
  auto numbers = twoNumberSum({3, 5, -4, 8, 11, 1, -1, 6}, 10);
  if (numbers.has_value())
  {
    cout << numbers->first << "," << numbers->second << endl;
  }
  else
  {
    cout << "not found\n";
  }
  return 0;
}