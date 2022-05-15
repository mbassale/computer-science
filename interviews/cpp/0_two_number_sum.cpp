#include <iostream>
#include <vector>
#include <unordered_set>
#include <optional>

using namespace std;

std::optional<std::pair<int, int>> twoNumberSum(vector<int> array, int targetSum)
{
  unordered_set<int> seen;
  auto it = array.begin();
  while (it != array.end())
  {
    auto other = targetSum - *it;
    if (seen.count(other))
    {
      return std::optional<std::pair<int, int>>({other, *it});
    }
    seen.insert(*it);
    it++;
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