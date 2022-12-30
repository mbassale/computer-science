#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

unordered_map<char, size_t> buildCharacterFrequencies(const string& s, bool includeSpace = false) {
  unordered_map<char, size_t> charFreqs;
  for (char c : s) {
    if (!includeSpace && isspace(c)) {
      continue;
    }
    const auto lowerChar = tolower(c);
    charFreqs[lowerChar]++;
  }
  return charFreqs;
}

// Example: taco cat -> tacocat -> t acoca t -> ta coc at -> tac o cat
// Character Frequencies: t:2 a:2 c:2 o:1
// Example: pale elap -> paleelap -> pale "" elap
// Character Frequencies: p:2 a:2 l:2 e:2
// In general:
// Character Frequencies: (x%2==0) or (x%2==0 and y==1)
// Time: O(n), with n=len(s) Space: O(n)
bool checkPalindromePermutation(const string& s) {
  // build character frequency table
  const auto charFreqs = buildCharacterFrequencies(s);

  // validate conditions
  auto it = charFreqs.begin();
  size_t oddCount = 0;
  size_t evenCount = 0;
  while (it != charFreqs.end()) {
    const auto freq = it->second;
    if (freq % 2 == 0) {
      evenCount++;
    } else {
      oddCount++;
    }
    it++;
  }

  // we can have at most 1 odd frequency (central character)
  if (oddCount > 1) {
    return false;
  }

  return true;
}

void invokeCheckPalindromePermutation(const string& s) {
  const auto start = high_resolution_clock::now();
  const auto result = checkPalindromePermutation(s);
  const auto stop = high_resolution_clock::now();
  const auto delta = duration_cast<microseconds>(stop - start);
  cout << "checkPalindromePermutation(" << s << ") = " << result
       << " Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeCheckPalindromePermutation("Tact coa");
  invokeCheckPalindromePermutation("pale   elap");
  invokeCheckPalindromePermutation("paleee lapp");
  return EXIT_SUCCESS;
}