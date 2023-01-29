#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

// Time: O(n), n=len(s) Space: O(n)
string stringCompression(const string& s) {
  string result;
  for (size_t i = 0; i < s.length(); i++) {
    uint8_t count = 1;
    while (i + 1 < s.length() && s[i] == s[i + 1] && count < 10) {
      count++;
      i++;
    }
    result.push_back(s[i]);
    result.push_back(count + '0');
  }
  return (result.length() < s.length()) ? result : s;
}

void invokeStringCompression(const string& s) {
  auto result = stringCompression(s);
  cout << "stringCompression(" << s << ") = " << result << endl;
}

int main(int argc, char* argv[]) {
  invokeStringCompression("aabccccaaa");
  invokeStringCompression("111bbbbbb222222ee");
  return EXIT_SUCCESS;
}