#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Time: O(n^2) Space: O(1) 
void printPairs(const vector<int>& array) {
  for (size_t i = 0; i < array.size(); i++) {
    for (size_t j = 0; j < array.size(); j++) {
      cout << array[i] << "," << array[j] << endl;
    }
  }
}

int main(int argc, char *argv[]) {
  printPairs({ 1, 2, 3, 4, 5 });
  printPairs({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
  return EXIT_SUCCESS;
}