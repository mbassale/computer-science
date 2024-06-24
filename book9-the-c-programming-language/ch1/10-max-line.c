#include <stdio.h>

#define MAXLINE 1024 /* maximum input line size */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/*
 * Print longest input line
 */
int main(int argc, char *argv[]) {
  int len, max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = getline2(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  /* there was a longest line */
  if (max > 0) {
    printf("%d: %s\n", max, longest);
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
 * copy: copy string 'from' into 'to'.
 */
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
