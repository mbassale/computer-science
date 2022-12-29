#include <array>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

// Time: O(max(s1,s2)) Space: O(max(s1,s2))
bool checkPermutationHashMap(const string& s1, const string& s2) {
  if (s1.length() != s2.length()) {
    return false;
  }

  unordered_map<char, size_t> s1Freqs;
  for (char c : s1) {
    s1Freqs[c]++;
  }

  unordered_map<char, size_t> s2Freqs;
  for (char c : s2) {
    s2Freqs[c]++;
  }

  return s1Freqs == s2Freqs;
}

// Time: O(N*log(N)) Space: O(1) with N = max(len(s1), len(s2))
bool checkPermutationSorting(string s1, string s2) {
  if (s1.length() != s2.length()) {
    return false;
  }

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  for (auto it1 = s1.begin(), it2 = s2.begin();
       it1 != s1.end() && it2 != s2.end(); it1++, it2++) {
    if (*it1 != *it2) {
      return false;
    }
  }
  return true;
}

constexpr int ALPHABET_SIZE = 26;

// Time: O(N) Space: O(1) with N = len(s)
array<size_t, ALPHABET_SIZE> buildAlphaFrequencies(const string& s) {
  array<size_t, ALPHABET_SIZE> charFreqs;
  charFreqs.fill(0);
  for (char c : s) {
    if (!isalpha(c)) {
      continue;
    }
    int idx = tolower(c) - 'a';
    charFreqs[idx]++;
  }
  return charFreqs;
}

// Time: O(N) with N = max(len(s1), len(s2))
// Space: O(1) 26 alpha chars
bool checkPermutationAlphaArray(string s1, string s2) {
  if (s1.length() != s2.length()) {
    return false;
  }
  // O(1) std::move()
  const auto s1Freqs = buildAlphaFrequencies(s1);
  // O(1) std::move()
  const auto s2Freqs = buildAlphaFrequencies(s2);
  // O(N)
  return s1Freqs == s2Freqs;
}

void invokeCheckPermutation(const string& s1, const string& s2) {
  auto start = high_resolution_clock::now();
  auto result = checkPermutationHashMap(s1, s2);
  auto stop = high_resolution_clock::now();
  cout << "checkPermutationHashMap(" << s1 << "," << s2 << ") = " << result
       << " Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;

  start = high_resolution_clock::now();
  result = checkPermutationAlphaArray(s1, s2);
  stop = high_resolution_clock::now();
  cout << "checkPermutationAlphaArray(" << s1 << "," << s2 << ") = " << result
       << " Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;

  start = high_resolution_clock::now();
  result = checkPermutationSorting(s1, s2);
  stop = high_resolution_clock::now();
  cout << "checkPermutationSorting(" << s1 << "," << s2 << ") = " << result
       << " Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeCheckPermutation("", "");
  invokeCheckPermutation("a", "a");
  invokeCheckPermutation("aa", "aa");
  invokeCheckPermutation("a", "b");
  invokeCheckPermutation("aa", "ab");
  invokeCheckPermutation("hello", "olleh");
  invokeCheckPermutation("marco", "ocram");
  invokeCheckPermutation("abccd", "abcd");
  return EXIT_SUCCESS;
}