#include <iostream>
#include <cstdlib>

using namespace std;

// Time: O(a/b) Space: O(a/b)
int integerDivision(int a, int b) {
  int count = 0;
  int sum = b;
  while (sum <= a) {
    sum += b;
    count++;
  }
  return count;
}

int sqrtHelper(int n, int min, int max) {
  if (max < min) {
    return -1;
  }

  int guess = min + (max - min) / 2;
  int squareGuess = guess * guess;
  if (squareGuess == n) {
    return guess;
  } else if (squareGuess < n) {
    return sqrtHelper(n, guess + 1, max);
  } else {
    return sqrtHelper(n, min, guess - 1);
  }
}

// Time: O(log(n)) Space: O(log(n))
int integerSqrt(int n) {
  return sqrtHelper(n, 1, n);
}

// The runtime is the number of digits, so 10^d ~ n, if we apply log
// we will have d=log(n)
// Time: O(log(n)) Space: O(1)
int sumDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

bool isInOrder(string str) {
  for (size_t i = 1; i < str.length(); i++) {
    if (str[i - 1] > str[i]) {
      return false;
    }
  }
  return true;
}

void printSortedStrings(int k, string prefix) {
  if (k == 0) {
    if (isInOrder(prefix)) {
      cout << prefix << ",";
    }
  } else {
    for (char c = 'a'; c <= 'z'; c++) {
      printSortedStrings(k - 1, prefix + c);
    }
  }
}

// Time: O(k*c^k), where k=length of string, c=number of chars in alphabet.
// Space: O(c^k)
void printSortedStrings(int k) {
  printSortedStrings(k, "");
}

int main(int argc, char *argv[]) {
  cout << "integerDivision(500, 5) = " << integerDivision(500, 5) << endl;
  cout << "integerSqrt(100) = " << integerSqrt(100) << endl;
  cout << "integerSqrt(81) = " << integerSqrt(81) << endl;
  cout << "sumDigits(123456789) = " << sumDigits(123456789) << endl;
  cout << "printSortedStrings(2): ";
  printSortedStrings(2);
  cout << endl;
  return EXIT_SUCCESS;
}