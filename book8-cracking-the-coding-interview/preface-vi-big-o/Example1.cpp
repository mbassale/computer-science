#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Time: O(n) Space: O(1)
void foo(const vector<int>& array) {
  int sum = 0;
  int product = 1;
  // Time: O(n) Space: O(1)
  for (size_t i = 0; i < array.size(); i++) {
    sum += array[i];
  }

  // Time: O(n) Space: O(1)
  for (size_t i = 0; i < array.size(); i++) {
    product *= array[i];
  }

  cout << sum << ", " << product << endl;
}

int main(int argc, char *argv[]) {
  foo({1, 2, 3, 4, 5});
  foo({-1, -2, -3, -4, -5});
  return EXIT_SUCCESS;
}