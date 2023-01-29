#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

bool oneEditAway(const string& s1, const string& s2) {
  size_t changeCount = 0;
  for (size_t i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      changeCount++;
    }
  }
  return changeCount == 1;
}

bool oneInsertionAway(const string& s1, const string& s2) {
  size_t i = 0, j = 0;
  size_t changeCount = 0;
  while (i < s1.length() && j < s2.length()) {
    if (s1[i] != s2[j]) {
      if (i + 1 < s1.length() && s1[i + 1] == s2[j]) {
        changeCount++;
        i++;
      } else if (j + 1 < s2.length() && s1[i] == s2[j + 1]) {
        changeCount++;
        j++;
      } else {
        changeCount++;
        
      }
    }
    i++;
    j++;
  }
  if (i < s1.length() || j < s2.length()) {
    changeCount++;
  }
  return changeCount == 1;
}

// Time: O(N) with n=max(len(s1), len(s2)) Space: O(1)
bool oneChangeAway(const string& s1, const string& s2) {
  // test one edit away
  if (s1.length() == s2.length()) {
    return oneEditAway(s1, s2);
  } else if (s1.length() + 1 == s2.length()) {  // test one insertion away
    return oneInsertionAway(s1, s2);
  } else if (s1.length() == s2.length() + 1) {  // test one insertion away
    return oneInsertionAway(s2, s1);
  }
  return false;
}

void invokeOneChangeAway(const string& s1, const string& s2) {
  auto start = high_resolution_clock::now();
  auto result = oneChangeAway(s1, s2);
  auto stop = high_resolution_clock::now();
  auto delta = duration_cast<microseconds>(stop - start);
  cout << "oneChangeAway(" << s1 << "," << s2 << ") = " << result
       << " Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeOneChangeAway("pale", "ple");
  invokeOneChangeAway("pales", "pale");
  invokeOneChangeAway("pale", "bale");
  invokeOneChangeAway("pale", "bake");
  return EXIT_SUCCESS;
}