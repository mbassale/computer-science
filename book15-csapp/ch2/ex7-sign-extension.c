#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(const char* prefix, byte_pointer ptr, size_t sz) {
  byte_pointer p = ptr;
  printf("%s", prefix);
  while (p < (ptr+sz)) {
    printf("%hhx", *p++);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  short sx = -12345;
  printf("short: %hd\n", sx);
  show_bytes("repr: ", (byte_pointer)&sx, sizeof(short));
  unsigned short usx = sx;
  printf("unsigned short: %hu\n", usx);
  show_bytes("repr: ", (byte_pointer)&usx, sizeof(unsigned short));
  int x = sx;
  printf("int: %d\n", x);
  show_bytes("repr: ", (byte_pointer)&x, sizeof(int));
  unsigned ux = usx;
  printf("unsigned: %u\n", ux);
  show_bytes("repr: ", (byte_pointer)&ux, sizeof(unsigned));

  unsigned uy = sx;
  printf("short: %hd => unsigned: %u\n", sx, uy);
  show_bytes("repr: ", (byte_pointer)&uy, sizeof(unsigned));
}
