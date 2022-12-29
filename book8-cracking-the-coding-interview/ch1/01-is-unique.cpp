#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bitset>

using namespace std;
using namespace std::chrono;

// Time: O(N) Space: O(N)
bool isUniqueHashTable(const string& s) {
  unordered_map<char, int> charFreqs;
  for (char c : s) {
    charFreqs[c]++;
    if (charFreqs[c] > 1) {
      return false;
    }
  }
  return true;
}

constexpr static int ALPHABET_SIZE = 26;

// Time: O(N) Space: O(1)
bool isUniqueBitset(const string& s) {
  bitset<ALPHABET_SIZE> charExists;
  for (char c : s) {
    if (!isalpha(c)) {
      continue;
    }
    int idx = tolower(c) - 'a';
    if (charExists[idx]) {
      return false;
    }
    charExists.flip(idx);
  }
  return true;
}

// Time: O(N) Space: O(1)
bool isUniqueBits(const string& s) {
  uint32_t alphaMask = 0;
  for (char c : s) {
    if (!isalpha(c)) {
      continue;
    }
    uint8_t idx = tolower(c) - 'a';
    if (alphaMask & (1 << idx)) {
      return false;
    }
    alphaMask |= 1 << idx;
  }
  return true;
}

// Time: O(N*log(N)) Space: O(1)
bool isUniqueSorting(string s) {
  sort(s.begin(), s.end());
  for (size_t i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) {
      return false;
    }
  }
  return true;
}

void invokeIsUnique(const string& s) {
  auto start = high_resolution_clock::now();
  auto result = isUniqueHashTable(s);
  auto stop = high_resolution_clock::now();
  auto delta = duration_cast<microseconds>(stop - start);
  cout << "isUniqueHashTable(" << s << ") = " << result
       << " Runtime: " << delta.count() << "us" << endl;

  start = high_resolution_clock::now();
  result = isUniqueBitset(s);
  stop = high_resolution_clock::now();
  delta = duration_cast<microseconds>(stop - start);
  cout << "isUniqueBitset(" << s << ") = " << result
       << " Runtime: " << delta.count() << "us" << endl;

  start = high_resolution_clock::now();
  result = isUniqueBits(s);
  stop = high_resolution_clock::now();
  delta = duration_cast<microseconds>(stop - start);
  cout << "isUniqueBits(" << s << ") = " << result
       << " Runtime: " << delta.count() << "us" << endl;

  start = high_resolution_clock::now();
  result = isUniqueSorting(s);
  stop = high_resolution_clock::now();
  delta = duration_cast<microseconds>(stop - start);
  cout << "isUniqueSorting(" << s << ") = " << result
       << " Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeIsUnique("abcdefg");
  invokeIsUnique("hello world");
  invokeIsUnique("Marco Bassaletti");
  invokeIsUnique("uncopyrightables");
  return EXIT_SUCCESS;
}