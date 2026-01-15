#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Print out the the string 's'*/
void ps_print(char *s) {
  uint32_t *lenptr = (uint32_t *)(s - 4);
  for (int j = 0; j < *lenptr; j++) {
    putchar(s[j]);
  }
  printf("\n");
}

/*
    Initialize a prefixed-length string 's' with the specified string 'init' of
   length 'ltn'.

    The created strings has the following layout:
    +----+------------\\\
    |LLLL|My string here
    +----+------------\\\

    Where LLLL are 4 unsigned bytes  stating the total length of the string.
    Thus this string is binary safe: zero bytes are permitted in the middle.

    WARN: this func does not check for buffer overflows.
 */
char *ps_create(char *init, size_t len) {
  char *s = malloc(4 + len + 1);
  uint32_t *lenptr = (uint32_t *)s;
  *lenptr = len;

  s += 4;
  for (int j = 0; j < len; j++) {
    s[j] = init[j]; // TODO: use memcpy()
  }
  s[len] = 0;
  return s;
}

// Free a previously created PS string
void ps_free(char *s) { free(s - 4); }

// Return the legth of  the string O(1) time.
uint32_t ps_len(char *s) {
  uint32_t *lenptr = (uint32_t *)(s - 4);
  return *lenptr;
}

int main(void) {

  char *mystring = ps_create("Hello World", 11);
  ps_print(mystring);
  ps_print(mystring);
  printf("%s %d\n", mystring, (int)ps_len(mystring));
  // make PL strings interoperable with "standard C strings"
  ps_free(mystring);
  // this chunck of memory would have been freed anyway since we are exiting the
  // program

  // It ould be heplful to add other 4 bytes in the string prefix to count its
  // references. That would make memory managment semi-automatic but it would be also cubersome to maintain.
  // A common solutiom to this issue is to use a `struct` .
  return 0;
}
