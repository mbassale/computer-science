#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Time: O(branches^depth), there are two branches per call
// Time: O(2^n) Space: O(n)
int fib(int n) {
  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

// Time: O(n) Space: O(n)
int fibMemo(int n, unordered_map<int, int>& memo) {
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }
  if (n <= 0) {
    memo[n] = 0;
  } else if (n == 1) {
    memo[n] = 1;
  } else {
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
  }
  return memo[n];
}

void callFib(int n, bool withMemoization) {
  const auto start = high_resolution_clock::now();
  int result = 0;
  if (withMemoization)
  {
    unordered_map<int, int> memo;
    result = fibMemo(n, memo);
  } else {
    result = fib(n);
  }
  const auto stop = high_resolution_clock::now();
  const auto delta = duration_cast<nanoseconds>(stop - start);
  if (withMemoization) {
    cout << "fibMemo(" << n << ") = ";
  } else
  {
    cout << "fib(" << n << ") = ";
  }
  cout << result << " Runtime: " << delta.count() << "ns" << endl;
}

int main(int argc, char *argv[]) {
  for (int i = 0; i <= 30; i++) {
    callFib(i, false);
    callFib(i, true);
  }
  return EXIT_SUCCESS;
}