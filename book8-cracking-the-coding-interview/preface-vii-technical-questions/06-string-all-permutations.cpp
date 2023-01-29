#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void findPermutations(string str, string suffix) {
  if (str.length() == 0) {
    cout << suffix << ", ";
    return;
  }
  for (size_t i = 0; i < str.length(); i++) {
    const auto c = str[i];
    const auto leftStr = str.substr(0, i);
    const auto rightStr = str.substr(i + 1);
    const auto rest = leftStr + rightStr;
    findPermutations(rest, suffix + c);
  }
}

void invokeFindPermutations(const string& s) {
  const auto start = high_resolution_clock::now();
  findPermutations(s, "");
  const auto stop = high_resolution_clock::now();
  const auto delta = duration_cast<microseconds>(stop - start);
  cout << "Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char *argv[]) {
  invokeFindPermutations("abc");
  invokeFindPermutations("abcd");
  invokeFindPermutations("abcde");
  return EXIT_SUCCESS;
}