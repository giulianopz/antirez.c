#include "stdio.h"

int main(void)
{

  int x = 5;
  int *y = &x;
  int **z = &y;
  printf("x is stored in %p and y is stored in%p\n", y, z);
  printf("number of bytes: x=%d, y=%d, z=%d\n", (int)sizeof(x), (int)sizeof(y), (int)sizeof(z));

  char mystr[] = "Hello World";
  char *p = mystr;
  // an array variable is basically a pointer to the first element of such array
  printf("at %p I can see: '%s'\n", mystr, mystr);
  printf("%c=%c\n", *p, p[0]);

  // beyond indexing, pointers allow us to perform math ops on them
  printf("%c%c%c%c%c\n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));

  char mystr2[] = "AABBCCDDEEFF";
  // the cast here is only meant to silence a compiler warning,
  // it does not affect the pointer size
  short *p2 = (short *)mystr2;
  // it prints out 16705, i.e. the decimal value of the hexadecimal representation of 'AA':
  // 65 is the ASCII code (decimal value) for 'A', see man ascii
  // (65)₁₀ = (41)₁₆ -> 0x4141 = (4141)₁₆ = (16705)₁₀
  // because:
  // (4141)₁₆ = (4 × 16³) + (1 × 16²) + (4 × 16¹) + (1 × 16⁰) = (16705)₁₀
  printf("%d\n", *p2);
  // each pointer increment is computed by adding the size of the pointer type,
  // 16 bit in the case of a short
  p2++;
  // prints 16962, i.e. 'BB' -> 66+(66*256)
  printf("%d\n", *p2);

  // just as p2 +=4
  printf("%d\n", p2[4]);

  // indexing beyond the memory really in used causes a program to access random data
  // or to crash with a segfault when a program tries to access memory out of its scope
  // e.g., printf("%d\n",  p2[-524165145646514264165]);

  char mystr3[] = "AABBCCDDEEFF";
  char *p3 = mystr3;

  printf("at the beginning p is %p\n", p3);
  while (*p3 != 0)
  {
    putchar(*p3);
    p3++;
  }
  printf("\n");
  printf("at the end p is %p\n", p3);

  // to print a pointer in decimal format:
  // printf("at the end p is %lu\n", (unsigned long)p3);

  return 0;
}
