#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int c;
  int new_lines = 0, tabs = 0, whitespace = 0;
  while((c = getchar()) != EOF) {
    if (c == '\n') {
      ++new_lines;
    } else if (c == '\t') {
      ++tabs;
    } else if (isblank(c)) {
      ++whitespace;
    }
  }
  printf("New Lines: %d\nTabs: %d\nWhitespace: %d\n", new_lines, tabs, 
         whitespace);
  return 0;
}
