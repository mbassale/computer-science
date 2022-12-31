#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
  Problem: Matrix M x N, zero row and column if any element is zero.
*/

// Time: O(N) Space: O(1)
template <typename T>
void zeroMatrixRow(vector<vector<T>>& matrix, size_t row) {
  for (size_t col = 0; col < matrix[row].size(); col++) {
    if (matrix[row][col] != 0) {
      matrix[row][col] = 0;
    }
  }
}

// Time: O(M) Space: O(1)
template <typename T>
void zeroMatrixCol(vector<vector<T>>& matrix, size_t col) {
  for (size_t row = 0; row < matrix.size(); row++) {
    if (matrix[row][col] != 0) {
      matrix[row][col] = 0;
    }
  }
}

// Time: O(M*N) Space: O(M+N)
template <typename T>
void zeroMatrixExtraStorage(vector<vector<T>>& matrix) {
  unordered_map<size_t, bool> rowsToBeZeroed;
  unordered_map<size_t, bool> colsToBeZeroed;

  // find zeros, fill hash tables for rows and cols to be zeroed
  for (size_t row = 0; row < matrix.size(); row++) {
    for (size_t col = 0; col < matrix[row].size(); col++) {
      // Time: O(1)
      if (colsToBeZeroed.find(col) != colsToBeZeroed.end()) {
        col++;
        continue;
      }
      if (matrix[row][col] == 0) {
        rowsToBeZeroed[row] = true;
        colsToBeZeroed[col] = true;
        row++;
        col++;
        continue;
      }
    }
  }

  // zero the rows
  auto rowIt = rowsToBeZeroed.begin();
  while (rowIt != rowsToBeZeroed.end()) {
    const auto row = rowIt->first;
    zeroMatrixRow(matrix, row);
    rowIt++;
  }

  // zero the cols
  auto colIt = colsToBeZeroed.begin();
  while (colIt != colsToBeZeroed.end()) {
    const auto col = colIt->first;
    zeroMatrixCol(matrix, col);
    colIt++;
  }
}

template <typename T>
void zeroMatrixNoExtraStorage(vector<vector<T>>& matrix) {
  // TODO: implement using matrix itself as extra storage.
}

template <typename T>
void printMatrix(vector<vector<T>>& matrix) {
  for (auto it = matrix.cbegin(); it != matrix.cend(); it++) {
    for (auto itemIt = it->cbegin(); itemIt != it->cend(); itemIt++) {
      cout << *itemIt << " ";
    }
    cout << endl;
  }
}

template <typename T>
void invokeZeroMatrix(const vector<vector<T>>& matrix) {
  auto m = matrix;
  cout << "Before:" << endl;
  printMatrix(m);
  auto start = high_resolution_clock::now();
  zeroMatrixExtraStorage(m);
  auto stop = high_resolution_clock::now();
  cout << "After zeroMatrixExtraStorage(): " << endl;
  printMatrix(m);
  cout << "Runtime: " << duration_cast<microseconds>(stop - start).count()
       << "us" << endl;
}

int main(int argc, char* argv[]) {
  vector<vector<int>> matrix({{1, 2, 3}, {4, 0, 6}, {7, 8, 9}});
  invokeZeroMatrix(matrix);
  matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 0, 12}, {13, 14, 15, 16}};
  invokeZeroMatrix(matrix);
  return EXIT_SUCCESS;
}