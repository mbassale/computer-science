#include "lc-utility.h"

using std::swap;

void mirrorX(vector<vector<int>>& image) {
  for (auto& row : image) {
    size_t left = 0;
    size_t right = row.size() - 1;
    while (left < right) {
      const auto tmp = row[left];
      row[left] = row[right];
      row[right] = tmp;
      left++;
      right--;
    }
  }
}

void transpose(vector<vector<int>>& image) {
  for (size_t i = 0; i < image.size(); i++) {
    for (size_t j = 0; j < i; j++) {
      const auto tmp = image[i][j];
      image[i][j] = image[j][i];
      image[j][i] = tmp;
    }
  }
}

void rotate(vector<vector<int>>& image) {
  transpose(image);
  mirrorX(image);
}

void printImage(const vector<vector<int>>& image) {
  for (const auto& row : image) {
    for (const auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

void testCase(vector<vector<int>> image) {
  cout << "Original:" << endl;
  printImage(image);
  cout << "Rotated:" << endl;
  rotate(image);
  printImage(image);
  cout << endl;
}

int main(int argc, char* argv[]) {
  testCase({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  testCase({{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});

  return 0;
}
