#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Time: O(log(n)) Space: O(log(n))
int powersOf2(int n) {
  if (n < 1) {
    cout << 0 << ",";
    return 0;
  } else if (n == 1) {
    cout << 1 << ",";
    return 1;
  } else {
    int prev = powersOf2(n / 2);
    int curr = prev * 2;
    cout << curr << ",";
    return curr;
  }
}

void callPowersOf2(int n) {
  cout << "powersOf2(" << n << "): ";
  const auto start = high_resolution_clock::now();
  powersOf2(n);
  const auto stop = high_resolution_clock::now();
  const auto delta = duration_cast<nanoseconds>(stop - start);
  cout << endl << "Runtime: " << delta.count() << "ns" << endl;
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < 1073741824; i *= 2) {
    callPowersOf2(i);
  }
    return EXIT_SUCCESS;
}