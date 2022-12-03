#include <cstdlib>
#include <iostream>

using namespace std;

// Time: O(n^(1/2)) Space: O(1)
bool isPrime(int n) {
  for (int x = 2; x * x <= n; x++) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  for (int i = 2; i <= 100; i++) {
    cout << "isPrime(" << i << ") = " << (isPrime(i) ? "true" : "false") << endl;
  }
  return EXIT_SUCCESS;
}