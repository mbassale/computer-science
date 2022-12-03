#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Time: O(n^2 * n!) Space: O(n)
void permutation(string str, string prefix) {
  if (str.length() == 0) {
    cout << prefix << ",";
  } else {
    for (size_t i = 0; i < str.length(); i++) {
      auto rem = str.substr(0, i) + str.substr(i + 1);
      permutation(rem, prefix + str[i]);
    }
  }
}

void callPermutation(string str) {
  const auto start = high_resolution_clock::now();
  cout << "permutation(" << str << "): ";
  permutation(str, "");
  const auto stop = high_resolution_clock::now();
  const auto duration = duration_cast<nanoseconds>(stop - start);
  cout << endl << "Runtime: " << duration.count() << "ns" << endl;
}

int main(int argc, char *argv[]) {
  callPermutation("a");
  callPermutation("ab");
  callPermutation("abc");
  callPermutation("abcd");
  callPermutation("abcde");
  return EXIT_SUCCESS;
}