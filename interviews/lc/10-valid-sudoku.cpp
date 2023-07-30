#include <complex>
#include <cstdlib>
#include "lc-utility.h"

inline bool isValidNum(char c) {
  return c != '.';
}

inline int char2num(char c) {
  return c - '0';
}

inline int getBox(int row, int col) {
  int box = (row / 3) * 3;
  if (col < 3) {
    ;
  } else if (col < 6) {
    box += 1;
  } else if (col < 9) {
    box += 2;
  }
  return box;
}

bool isValidSudoku(const vector<vector<char>>& board) {
  int rows[9];
  int columns[9];
  int boxes[9];
  memset(rows, 0, sizeof(int) * 9);
  memset(columns, 0, sizeof(int) * 9);
  memset(boxes, 0, sizeof(int) * 9);

  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      const char c = board[row][col];
      if (!isValidNum(c)) {
        continue;
      }
      const int num = char2num(c);
      const int mask = 1 << (num - 1);

      if ((rows[row] & mask) > 0) {
        return false;
      }
      if ((columns[col] & mask) > 0) {
        return false;
      }
      const auto box = getBox(row, col);
      if ((boxes[box] & mask) > 0) {
        return false;
      }

      rows[row] |= mask;
      columns[col] |= mask;
      boxes[box] |= mask;
    }
  }
  return true;
}

void printBoard(const vector<vector<char>>& board) {
  for (int row = 0; row < board.size(); row++) {
    for (int col = 0; col < board[row].size(); col++) {
      const char c = board[row][col];
      cout << c << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << "Board: " << endl;
  printBoard(board);
  cout << "IsValid: " << (isValidSudoku(board) ? "true" : "false") << endl;

  return EXIT_SUCCESS;
}
