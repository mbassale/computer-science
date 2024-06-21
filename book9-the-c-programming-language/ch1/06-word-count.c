#include <ctype.h>
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main(int argc, char *argv[]) {
  int c, nl = 0, nw = 0, nc = 0, state = OUT;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (isspace(c)) {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("Lines: %d, Words: %d, Characters: %d\n", nl, nw, nc);
  return 0;
}
