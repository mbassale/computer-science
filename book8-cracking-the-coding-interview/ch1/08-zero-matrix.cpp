#include <chrono>
#include <iomanip>
#include <iostream>
#include <limits>
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

  // explore for zeroes
  for (size_t row = 0; row < matrix.size(); row++) {
    for (size_t col = 0; col < matrix[row].size(); col++) {
      if (matrix[row][col] == 0) {
        // mark upper row and left column for zeroing
        matrix[row][0] = numeric_limits<T>::max();
        matrix[0][col] = numeric_limits<T>::max();
        break;
      }
    }
  }

  // zero the rows
  for (size_t row = 0; row < matrix.size(); row++) {
    if (matrix[row][0] == numeric_limits<T>::max()) {
      zeroMatrixRow(matrix, row);
    }
  }

  // zero the cols
  for (size_t col = 0; col < matrix[0].size(); col++) {
    if (matrix[0][col] == numeric_limits<T>::max()) {
      zeroMatrixCol(matrix, col);
    }
  }
}

template <typename T>
void printMatrix(vector<vector<T>>& matrix) {
  for (auto it = matrix.cbegin(); it != matrix.cend(); it++) {
    for (auto itemIt = it->cbegin(); itemIt != it->cend(); itemIt++) {
      cout << std::setfill('0') << std::setw(2) << *itemIt << " ";
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
  cout << "After zeroMatrixExtraStorage():" << endl;
  printMatrix(m);
  cout << "Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;

  m = matrix;
  cout << "Before:" << endl;
  printMatrix(m);
  start = high_resolution_clock::now();
  zeroMatrixNoExtraStorage(m);
  stop = high_resolution_clock::now();
  cout << "After zeroMatrixNoExtraStorage():" << endl;
  printMatrix(m);
  cout << "Runtime: " << duration_cast<nanoseconds>(stop - start).count()
       << "ns" << endl;
}

int main(int argc, char* argv[]) {
  vector<vector<int>> matrix({{1, 2, 3}, {4, 0, 6}, {7, 8, 9}});
  invokeZeroMatrix(matrix);
  matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 0, 12}, {13, 14, 15, 16}};
  invokeZeroMatrix(matrix);
  return EXIT_SUCCESS;
}