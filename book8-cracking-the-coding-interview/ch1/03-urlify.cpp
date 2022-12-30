#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

// Time: O(n), n = len(s) Space: O(1)
size_t countSpace(const string& s, size_t sz) {
  size_t spaces = 0;
  for (size_t i = 0; i < sz; i++) {
    if (isspace(s[i])) {
      spaces++;
    }
  }
  return spaces;
}

// Time: O(n) Space: O(1)
void urlify(string& s, size_t trueSize) {

  int spaceCount = countSpace(s, trueSize);

  int insertIdx = s.length() - 1;
  while (spaceCount > 0 && insertIdx >= 0) {

    // find rightIdx of next word, from right to left
    int rightIdx = insertIdx - 1;
    while (rightIdx > 0 && isspace(s[rightIdx])) {
      rightIdx--;
    }

    // swap characters with empty spaces, from right to left
    while (rightIdx > 0 && !isspace(s[rightIdx])) {
      swap(s[rightIdx], s[insertIdx]);
      rightIdx--;
      insertIdx--;
    }

    // if we have an space, fill with escape sequence %20, from right to left
    if (isspace(s[insertIdx])) {
      s[insertIdx--] = '0';
      s[insertIdx--] = '2';
      s[insertIdx--] = '%';
      spaceCount--;
    }
  }
}

void invokeUrlify(string s) {
  const auto trueSize = s.length();
  auto spaces = countSpace(s, trueSize);
  while (spaces-- > 0) {
    s.push_back(' ');
    s.push_back(' ');
  }
  cout << "String: " << s << " TrueSize: " << trueSize
       << " Size: " << s.length() << endl;
  const auto start = high_resolution_clock::now();
  urlify(s, trueSize);
  const auto stop = high_resolution_clock::now();
  const auto delta = duration_cast<microseconds>(stop - start);
  cout << "Urlify: " << s << " Runtime: " << delta.count() << "us" << endl;
}

int main(int argc, char* argv[]) {
  invokeUrlify("Mr John Smith");
  invokeUrlify("Hello World!");
  invokeUrlify(
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
      "tempor incididunt ut labore et dolore magna aliqua");
  return EXIT_SUCCESS;
}