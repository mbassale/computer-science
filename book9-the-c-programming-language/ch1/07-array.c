#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c, i, nwhite = 0, nother = 0;
  int ndigit[10];
  memset(ndigit, 0, sizeof(int)*10);

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (isspace(c)) {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits =");
  for (i = 0; i < 10; i++) {
    printf(" %d", ndigit[i]);
  }
  printf(", whitespace = %d, other=%d\n", nwhite, nother);
  return 0;
}
