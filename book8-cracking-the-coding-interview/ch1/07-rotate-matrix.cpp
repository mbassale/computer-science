#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
Problem: Rotate 90deg a N x N matrix.

Example: 3x3 Matrix

Original:
1 2 3
4 5 6
7 8 9

Transpose:
1 4 7
2 5 8
3 6 9

Mirror along X axis:
7 4 1
8 5 2
9 6 3
*/

// Time: O(N^2) Space: O(1)
template<typename T>
void transpose(vector<vector<T>>& matrix) {
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = i; j < matrix[i].size(); j++){
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}

// Time: O(N^2) Space: O(1)
template<typename T>
void mirrorX(vector<vector<T>>& matrix) {
  for (size_t i = 0; i < matrix.size(); i++) {
    auto leftIt = matrix[i].begin();
    auto rightIt = matrix[i].end() - 1;
    while (leftIt < rightIt) {
      swap(*leftIt, *rightIt);
      leftIt++;
      rightIt--;
    }
  }
}

// Time: O(N^2) Space: O(1)
template<typename T>
void rotate90(vector<vector<T>>& matrix) {
  if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
    return;
  }
  transpose(matrix);
  mirrorX(matrix);
}

template<typename T>
void rotate90Layers(vector<vector<T>>& matrix) {
  if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
    return;
  }

  int sz = matrix.size();
  for (int layer = 0; layer < sz / 2; layer++) {
    const auto first = layer;
    const auto last = sz - 1 - layer;
    for (int i = first; i < last; i++) {
      const auto offset = i - first;
      const auto top = matrix[first][i];

      // left -> top
      matrix[first][i] = matrix[last-offset][first];

      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];

      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];

      // top -> right
      matrix[i][last] = top;
    }
  }
}

template<typename T>
void printMatrix(vector<vector<T>>& matrix) {
  for (auto it = matrix.cbegin(); it != matrix.cend(); it++) {
    for (auto itemIt = it->cbegin(); itemIt != it->cend(); itemIt++) {
      cout << *itemIt << " ";
    }
    cout << endl;
  }
}

template<typename T>
void invokeRotate90(vector<vector<T>>& matrix) {
  auto m = matrix;
  cout << "Before:" << endl;
  printMatrix(m);
  auto start = high_resolution_clock::now();
  rotate90(m);
  auto stop = high_resolution_clock::now();
  cout << "After rotate90():" << endl;
  printMatrix(m);
  cout << "Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;

  m = matrix;
  cout << "Before:" << endl;
  printMatrix(m);
  start = high_resolution_clock::now();
  rotate90(m);
  stop = high_resolution_clock::now();
  cout << "After rotate90Layers():" << endl;
  printMatrix(m);
  cout << "Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;
}

vector<vector<int>> generateIntegerSquareMatrix(size_t dim) {
  int nextValue = 1;
  vector<vector<int>> matrix;
  for (size_t i = 0; i < dim; i++) {
    vector<int> row;
    for (size_t j = 0; j < dim; j++) {
      row.push_back(nextValue++);
    }
    matrix.push_back(row);
  }
  return matrix;
}

int main(int argc, char *argv[]) {
  auto matrix = generateIntegerSquareMatrix(5);
  invokeRotate90(matrix);
  matrix = generateIntegerSquareMatrix(20);
  invokeRotate90(matrix);
  return EXIT_SUCCESS;
}