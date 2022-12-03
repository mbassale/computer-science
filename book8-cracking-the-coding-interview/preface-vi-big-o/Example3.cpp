#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void printUnorderedPairs(const vector<int>& array) {
  // (n-1)+(n-2)+(n-3)+...+3+2+1
  // 1+2+3+...+(n-3)+(n-2)+(n-1) = n(n-1)/2 = O(N^2)
  for (size_t i = 0; i < array.size(); i++) {
    for (size_t j = i + 1; j < array.size(); j++) {
      cout << array[i] << "," << array[j] << endl;
    }
  }
}

int main(int argc, char *argv[]) {
  printUnorderedPairs({ 1, 2, 3, 4, 5 });
  printUnorderedPairs({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
  return EXIT_SUCCESS;
}