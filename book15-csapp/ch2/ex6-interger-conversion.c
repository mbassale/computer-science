#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

void print_bytes(void *p, size_t sz) {
  uint8_t *pb = (uint8_t*)p;
  for (int i = 0; i < sz; i++) {
    printf("%02x", *(pb+i));
  }
}

/**
  * is_negative: assumes signed number in two-complement encoding.
  *              Returns 1 is if negative, 0 otherwise.
  */
int is_negative(void *p, size_t sz) {
  // on little-endian, get the most significant byte
  uint8_t msb = *(uint8_t*)(p+sz-1);
  return (msb & 0x80) > 0;
}

int main(int argc, char *argv[]) {
  short v = -12345;
  printf("short: %hd\n", v);
  printf("repr: ");
  print_bytes(&v, sizeof(short));
  printf("\n");
  printf("two-complement negative? %d\n", is_negative(&v, sizeof(short)));

  unsigned short uv = (unsigned short)v;
  printf("unsigned short: %hu\n", uv);
  printf("repr: ");
  print_bytes(&uv, sizeof(unsigned short));
  printf("\n");
  printf("two-complement negative? %d\n", is_negative(&v, sizeof(unsigned short)));

  unsigned u = UINT_MAX;
  printf("uint: %u\n", u);
  printf("repr: ");
  print_bytes(&u, sizeof(unsigned));
  printf("\n");

  int tu = (int)u;
  printf("int: %d\n", tu);
  printf("repr: ");
  print_bytes(&tu, sizeof(int));
  printf("\n");

  int x1 = -1;
  unsigned u1 = pow(2, 31);
  printf("x = %u = %d = %x\n", x1, x1, x1);
  printf("u = %u = %d = %x\n", u1, u1, u1);


  printf("\nSigned to Unsigned Convertion Pitfalls:\n");
  printf("-2147483647-1 == 2147483648U = %d\n", -2147483647-1 == 2147483648U);
  printf("-2147483647-1 < 2147483647  = %d\n", -2147483647-1 < 2147483647);
  printf("-2147483647-1U < 2147483647 = %d\n", ((unsigned)(-2147483647-1)) < 2147483647);
  printf("-2147483647-1 < -2147483647 = %d\n", -2147483647-1 < -2147483647);
  printf("-2147483647-1U < -2147483647 = %d\n", ((unsigned)(-2147483647-1)) < -2147483647);

  return 0;
}
