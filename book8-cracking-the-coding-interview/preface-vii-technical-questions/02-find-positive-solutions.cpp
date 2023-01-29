#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

// Time: O(n^4) Space: O(1)
size_t findSolutionsBruteForce(int min, int max) {
  size_t solutionCount = 0;
  for (int a = min; a <= max; a++) {
    for (int b = min; b <= max; b++) {
      for (int c = min; c <= max; c++) {
        for (int d = min; d <= max; d++) {
          const auto lhs = pow(a, 3) + pow(b, 3);
          const auto rhs = pow(c, 3) + pow(d, 3);
          if (lhs == rhs) {
            solutionCount++;
          }
        }
      }
    }
  }
  return solutionCount;
}

// Time: O(n^4) Space: O(1)
size_t findSolutionsBruteForceBreakInLast(int min, int max) {
  size_t solutionCount = 0;
  for (int a = min; a <= max; a++) {
    for (int b = min; b <= max; b++) {
      for (int c = min; c <= max; c++) {
        for (int d = min; d <= max; d++) {
          const auto lhs = pow(a, 3) + pow(b, 3);
          const auto rhs = pow(c, 3) + pow(d, 3);
          if (lhs == rhs) {
            solutionCount++;
            break;  // break and don't continue checking for other values
          }
        }
      }
    }
  }
  return solutionCount;
}

// Time: O(n^3) Space: O(1)
size_t findSolutionsBruteForceUseCubeRoot(int min, int max) {
  size_t solutionCount = 0;
  for (int a = min; a <= max; a++) {
    for (int b = min; b <= max; b++) {
      for (int c = min; c <= max; c++) {
        int d = cbrt(pow(a, 3) + pow(b, 3) - pow(c, 3));
        const auto lhs = pow(a, 3) + pow(b, 3);
        const auto rhs = pow(c, 3) + pow(d, 3);
        if (lhs == rhs) {
          solutionCount++;
        }
      }
    }
  }
  return solutionCount;
}

// Time: O(n^2) Space: O(n^2)
size_t findSolutionsHashmap(int min, int max) {
  size_t solutionCount = 0;
  unordered_map<int, pair<int, int>> hash;

  for (int a = min; a <= max; a++) {
    for (int b = min; b <= max; b++) {
      const auto lhs = pow(a, 3) + pow(b, 3);
      hash[lhs] = {a, b};
    }
  }

  for (int c = min; c <= max; c++) {
    for (int d = min; d <= max; d++) {
      const auto rhs = pow(c, 3) + pow(d, 3);
      if (hash.find(rhs) != hash.end()) {
        solutionCount++;
      }
    }
  }
  return solutionCount;
}

int main(int argc, char* argv[]) {

  cout << "findSolutionsBruteForceUseCubeRoot(1, 1000) = ";
  auto start = high_resolution_clock::now();
  auto solutionCount = findSolutionsBruteForceUseCubeRoot(1, 1000);
  auto stop = high_resolution_clock::now();
  cout << solutionCount << " ";
  auto delta = duration_cast<milliseconds>(stop - start);
  cout << "Runtime: " << delta.count() << "ms" << endl;

  cout << "findSolutionsHashmap(1, 1000) = ";
  start = high_resolution_clock::now();
  solutionCount = findSolutionsHashmap(1, 1000);
  stop = high_resolution_clock::now();
  cout << solutionCount << " ";
  delta = duration_cast<milliseconds>(stop - start);
  cout << "Runtime: " << delta.count() << "ms" << endl;

  return EXIT_SUCCESS;
}