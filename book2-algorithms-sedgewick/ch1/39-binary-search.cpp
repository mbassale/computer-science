#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

namespace mbassale {

template <typename T>
size_t rank(T key, const vector<T>& a, size_t left = 0,
            size_t right = SIZE_T_MAX) {
  if (right == SIZE_T_MAX) {
    right = a.size() - 1;
  }
  if (left > right || left < 0 || right >= a.size()) {
    return SIZE_T_MAX;
  }
  size_t mid = left + (right - left) / 2;
  const auto val = a[mid];
  if (val == key) {
    return mid;
  } else if (key < val && mid > 0) {
    return rank(key, a, left, mid - 1);
  } else {
    return rank(key, a, mid + 1, right);
  }
}

}  // namespace mbassale

/*=============================================================================
Execution Output:
mbassale@MacBook-Pro ch1 % ./39-binary-search ../data/tinyW.txt < ../data/tinyT.txt 
rank(3, {1,2,3}) = 2
rank(2, {1,2,3}) = 1
rank(1, {1,2,3}) = 0
rank(0, {1,2,3}) = 18446744073709551615
50
99
13
=============================================================================*/

int main(int argc, char* argv[]) {
  cout << "rank(3, {1,2,3}) = " << mbassale::rank(3, {1, 2, 3}) << endl;
  cout << "rank(2, {1,2,3}) = " << mbassale::rank(2, {1, 2, 3}) << endl;
  cout << "rank(1, {1,2,3}) = " << mbassale::rank(1, {1, 2, 3}) << endl;
  cout << "rank(0, {1,2,3}) = " << mbassale::rank(0, {1, 2, 3}) << endl;

  vector<int> numbers;
  ifstream fin(argv[1]);
  if (!fin.is_open()) {
    cerr << "Cannot Open File: " << argv[1];
  }

  string line;
  while (!std::getline(fin, line).eof()) {
    numbers.push_back(stoi(line));
  }
  sort(numbers.begin(), numbers.end());

  while (!std::getline(cin, line).eof()) {
    const auto n = stoi(line);
    if (mbassale::rank(n, numbers) == SIZE_T_MAX) {
      cout << n << endl;
    }
  }

  return EXIT_SUCCESS;
}