/*
 * Practice Problem 2.12
 * VAX bis (bit set) and bic (bit clear)
 */

#include <stdio.h>
#include <stdlib.h>

/* Sets z to 1 at each bit position where m is 1 */
int bis(int x, int m) {
  return x|m;
}

/* Sets z to 0 at each bit position where m is 1 */
int bic(int x, int m) {
  return x&~m;
}

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
  return bis(x, y);
}

/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
  return bis(bic(x, y), bic(y, x));
}

int main(int argc, char *argv[]) {
  unsigned int x0 = 0xCAFEBABE;
  unsigned int x1 = 0xDEADBEEF;
  printf("%u | %u = %u, Expected: %u\n", x0, x1, bool_or(x0, x1), x0|x1);

  printf("%u ^ %u = %u, Expected: %u\n", x0, x1, bool_xor(x0, x1), x0^x1);
  return 0;
}
