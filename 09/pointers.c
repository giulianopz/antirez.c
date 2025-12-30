#include "stdio.h"

void incr(int *p) { *p = *p + 1; }

int main(void) {

  int x = 5;
  printf("%d\n", x);
  // this way of declaring a pointer is preferable over `int* x`
  // since `int* x, z` would declare only the former as a pointer
  int *y = 0;
  // prints nil memory address
  // equal to:
  // int *y = NULL;
  printf("%p\n", y);

  // reassign y to the address where x is stored
  y = &x;
  printf("x is stored at the address: %p\n", y);

  // derefence the pointer to change its value
  *y = 10;
  // having declare the pointer type makes it safe to assingn an int value to it
  printf("x is now: %d\n", x);
  // it can be rewritten equally
  // since pointers are can be referenced as arrays
  y[0] = 10;

  printf("x was now: %d\n", x);
  incr(y);
  // or
  // incr(&x);
  printf("x is now: %d\n", x);

  return 0;
}
