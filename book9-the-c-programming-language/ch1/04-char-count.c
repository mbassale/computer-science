#include <stdio.h>

int main(int argc, char *argv[]) {
  unsigned long nc;
  for (nc = 0; getchar() != EOF; nc++);
  printf("%lu\n", nc);
  return 0;
}
