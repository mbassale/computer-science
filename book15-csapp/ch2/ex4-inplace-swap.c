#include <stdio.h>
#include <limits.h>

void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverse_array(int a[], size_t cnt) {
  int first, last;
  for (first = 0, last = cnt - 1;
       first < last;
       first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }
}

void print_array(int a[], size_t cnt) {
  int i;
  for (i = 0; i < cnt; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int arr1[] = {1,2,3,4,5,6,7,8,9,10};
  size_t sz = 10;
  print_array(arr1, sz);
  reverse_array(arr1, sz);
  print_array(arr1, sz);
  reverse_array(arr1, sz);
  print_array(arr1, sz);
  return 0;
}
