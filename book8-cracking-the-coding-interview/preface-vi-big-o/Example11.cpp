#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Time: O(n) Space: O(n)
int factorial(uint64_t n) {
  if (n < 0) {
    return -1;
  } else if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

void callFactorial(uint64_t n) {
  const auto start = high_resolution_clock::now();
  int result = factorial(n);
  const auto stop = high_resolution_clock::now();
  const auto duration = duration_cast<nanoseconds>(stop - start);
  cout << "factorial(" << n << ") = " << result << " " << duration.count() << "ns" << endl;
}

int main(int argc, char *argv[]) {
  callFactorial(10);
  callFactorial(12);
  callFactorial(15);
  return EXIT_SUCCESS;
}