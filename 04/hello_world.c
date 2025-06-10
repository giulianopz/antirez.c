#include "stdio.h"
#include "limits.h"

void clear(void) {
    printf("\x1b[H");
}

int main(void) {
    char c = 1; // 8 bit
    short s = 2000; // 6 bits, 2 bytes
    int x = 5; // 4 byte, 32 bytes
    long l = 10; // same size as CPU word 


    // lu means 'long unsigned'
    printf("Hello World: int is %lu bytes\n", sizeof(x));
    // prints out 4 bytes
    // so unsigned int can range from 0 to 2^32-1,
    // signed int from -(2^31) to (2^31-1) instead 
    printf("Hello World: min is %d, max is %d\n",INT_MIN, INT_MAX);
    
    printf("long is %lu bytes\n", sizeof(l));

    return 0;
}
