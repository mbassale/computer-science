#include <iostream>
#include <vector>

using namespace std;

bool isValidSubsequence(const vector<int> &array, const vector<int> sequence)
{
  auto it = array.begin();
  auto seqIt = sequence.begin();
  while (it != array.end() && seqIt != sequence.end())
  {
    if (*it == *seqIt)
    {
      seqIt++;
    }
    it++;
  }
  return seqIt == sequence.end();
}

int main()
{
  bool result = false;
  const auto printValid = [&result]()
  {
    cout << "IsValidSubsequence: " << (result ? "true" : "false") << endl;
  };

  result = isValidSubsequence({5, 1, 22, 25, 6, -1, 8, 10}, {1, 6, -1, 10});
  printValid();

  result = isValidSubsequence({5, 1, 22, 25, 6, -1, 8, 10}, {22, 25, 6});
  printValid();

  result = isValidSubsequence({5, 1, 22, 25, 6, -1, 8, 10}, {5, 1, 22, 25, 6, -1, 8, 10});
  printValid();

  result = isValidSubsequence({5, 1, 22, 23, 6, -1, 8, 10}, {10});
  printValid();
  return 0;
}