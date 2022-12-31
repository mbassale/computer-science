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
  transpose(matrix);
  mirrorX(matrix);
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
  cout << "Before:" << endl;
  printMatrix(matrix);
  const auto start = high_resolution_clock::now();
  rotate90(matrix);
  const auto stop = high_resolution_clock::now();
  cout << "After:" << endl;
  printMatrix(matrix);
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