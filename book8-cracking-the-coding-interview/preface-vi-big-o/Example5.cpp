#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Time: O(n*m) with n = size(arrayA) and m = size(arrayB), Space: O(1)
void printUnorderedPairs(const vector<int>& arrayA, const vector<int>& arrayB) {
  // O(n)
  for (size_t i = 0; i < arrayA.size(); i++) {
    // O(m)
    for (size_t j = 0; j < arrayB.size(); j++) {
      for (size_t k = 0; k < 100000; k++) {
        cout << arrayA[i] << "," << arrayB[j] << endl;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  printUnorderedPairs({ 1, 2, 3, 4, 5 }, { 5, 6, 7, 8, 9, 10});
  return EXIT_SUCCESS;
}