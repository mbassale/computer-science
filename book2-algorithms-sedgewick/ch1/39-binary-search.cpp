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

int main(int argc, char* argv[]) {
  cout << "rank(3, {1,2,3}) = " << mbassale::rank(3, {1, 2, 3}) << endl;
  cout << "rank(2, {1,2,3}) = " << mbassale::rank(2, {1, 2, 3}) << endl;
  cout << "rank(1, {1,2,3}) = " << mbassale::rank(1, {1, 2, 3}) << endl;
  cout << "rank(0, {1,2,3}) = " << mbassale::rank(0, {1, 2, 3}) << endl;
  return EXIT_SUCCESS;
}