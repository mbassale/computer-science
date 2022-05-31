#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sortedSquaredArray(const vector<int> &array)
{
  vector<int> result(array.size(), 0);
  auto leftIt = array.begin();
  auto rightIt = array.end() - 1;
  auto outputIt = result.rbegin();
  while (outputIt != result.rend())
  {
    const auto leftSq = *leftIt * *leftIt;
    const auto rightSq = *rightIt * *rightIt;
    if (leftSq > rightSq)
    { // insert left at end
      *outputIt = leftSq;
      leftIt++;
    }
    else
    { // insert right at the end
      *outputIt = rightSq;
      rightIt--;
    }
    outputIt++;
  }
  return result;
}

int main()
{
  const auto printArray = [](const vector<int> &arr)
  {
    cout << "[ ";
    for (const auto &num : arr)
    {
      cout << num << " ";
    }
    cout << "]\n";
  };

  auto result = sortedSquaredArray({1, 2, 3, 5, 6, 8, 9});
  printArray(result);

  result = sortedSquaredArray({-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1});
  printArray(result);

  result = sortedSquaredArray({-1});
  printArray(result);

  result = sortedSquaredArray({1});
  printArray(result);

  result = sortedSquaredArray({});
  printArray(result);

  return 0;
}