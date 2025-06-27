#include <stdio.h>

int main(void)
{
    int i = 5;

    if (i > 3)
    {
        printf("i > 3\n");
    }
    else
    {
        printf("i < 3\n");
    }

    int j = 8;
    {
        int j = 5;
        printf("j (%zu bytes) stored at: %p\n", sizeof(j), &j);
    }
    printf("j (%zu bytes) stored at: %p\n", sizeof(j), &j);
    // the two variables are allocated one after the other
    // j (4 bytes) stored at: 0x7ffca2118da0
    // j (4 bytes) stored at: 0x7ffca2118d9c

    return 0;
}