#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // prints: expr1: 0.000000
  float expr1 = (3.14f + 1e20f)-1e20f;
  // prints: expr2: 3.140000
  float expr2 = 3.14f + (1e20f - 1e20f);
  printf("expr1: %f\nexpr2: %f\n", expr1, expr2);
  return 0;
}
