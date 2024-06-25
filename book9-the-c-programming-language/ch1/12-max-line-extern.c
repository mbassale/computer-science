#include <stdio.h>

#define MAXLINE 1024    /* maximum input line size */

int max;                /* maximum line length */
char line[MAXLINE];     /* current input line */
char longest[MAXLINE];  /* longest line saved */

int getline2(void);
void copy(void);

/*
 * Print longest line from stdin, this time using external variables.
 */
int main(int argc, char *argv[]) {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline2()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) {
    printf("%d: %s", max, longest);
  }
  return 0;
}

/*
 * getline: reads next line from stdin, returns line length.
 */
int getline2(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/*
 * copy: copies line into longest.
 */
void copy(void) {
  int i;
  extern char line[], longest[];
  i = 0;
  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}

