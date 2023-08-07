#include "lc-utility.h"

void reverseString(string& s) {
  if (s.length() <= 1) {
    return;
  }
  size_t left = 0, right = s.length() - 1;
  while (left < right) {
    const auto tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    left++;
    right--;
  }
}

void runTestCase(string s) {
  cout << "Original: " << s << endl;
  reverseString(s);
  cout << "Reversed: " << s << endl;
}

int main(int argc, char* argv[]) {
  runTestCase("Hello, world!");
  runTestCase("Lorem Ipsum Dolor Senet");
  runTestCase("");
  runTestCase("a");
  return 0;
}
