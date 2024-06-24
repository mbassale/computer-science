#include <stdio.h>
#include <string.h>

#define MAXLINE 1024 /* maximum input line size */

int getline2(char line[], int maxline);
void reverse(char reversed[], char original[]);

/*
 * Reverse input text, line by line.
 */
int main(int argc, char *argv[]) {
  int len;
  char line[MAXLINE];
  char reversed[MAXLINE];

  while ((len = getline2(line, MAXLINE)) > 0) {
    reverse(reversed, line);
    printf("%s", reversed);
  }
  return 0;
}

/*
 * getline2: read a line into buf, returns length.
 */
int getline2(char buf[], int maxsz) {
  int c, i;
  for (i = 0; i < maxsz - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    buf[i] = c;
  }
  if (c == '\n') {
    buf[i] = c;
    ++i;
  }
  buf[i] = '\0';
  return i;
}

/*
 * copy: copy 'from' into 'to'.
 */
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

/*
 * reverse: reverse string passed in 'original' and stores into 'reversed'.
 */
void reverse(char reversed[], char original[]) {
  copy(reversed, original);
  int len = strlen(reversed);
  int left = 0, right = len - 1;
  int tmp;
  while (left < right) {
    tmp = reversed[left];
    reversed[left] = reversed[right];
    reversed[right] = tmp;
    ++left;
    --right;
  }
}
