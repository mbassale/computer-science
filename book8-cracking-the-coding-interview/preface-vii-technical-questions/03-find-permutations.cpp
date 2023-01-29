#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

bool isPermutation(string str, unordered_map<char, int>& charFreqs) {
  unordered_map<char, int> strFreqs = charFreqs;
  for (char c : str) {
    if (strFreqs.find(c) == strFreqs.end() || strFreqs[c] == 0) {
      return false;
    }
    strFreqs[c]--;
  }
  auto it = strFreqs.begin();
  while (it != strFreqs.end()) {
    if (it->second > 0) {
      return false;
    }
    it++;
  }
  return true;
}

// Time: O(b*s) Space: O(s)
size_t findPermutations(string s, string b) {
  if (b.length() < s.length()) {
    return 0;
  }

  unordered_map<char, int> charFreqs;
  for (char c : s) {
    charFreqs[c]++;
  }

  size_t solutionCount = 0;
  size_t slidingWindowSize = s.length();
  for (size_t i = 0; i < b.length(); i++) {
    const auto windowStr = b.substr(i, s.length());
    if (isPermutation(windowStr, charFreqs)) {
      cout << windowStr << ",";
      solutionCount++;
    }
  }

  return solutionCount;
}

int main(int argc, char *argv[]) {
  string s = "abbc";
  string b = "cbabadcbbabbcbabaabccbabc";
  cout << "findPermutations(" << s << "," << b << ") = ";
  const auto start = high_resolution_clock::now();
  auto result = findPermutations(s, b);
  const auto end = high_resolution_clock::now();
  const auto delta = duration_cast<microseconds>(end - start);
  cout << " # Permutations: " << result << " Runtime: " << delta.count() << "us" << endl;
  return EXIT_SUCCESS;
}