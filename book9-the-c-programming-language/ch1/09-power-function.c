#include <stdio.h>

int power(int m, int n);

int main(int argc, char *argv[]) {
  int i;
  for (i = 0; i < 10; i++) {
    printf("power(2, %d)) = %d, power(-3, %d) = %d\n", i, power(2, i), i, power(-3, i));
  }
  return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
  int i, p;
  p = 1;
  for (i = 1; i <= n; ++i) {
    p = p * base;
  }
  return p;
}
