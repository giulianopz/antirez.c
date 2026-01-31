#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pls
{
    long len; // 8 bytes
    char *str; // this is effectively a pointer of 8 bytes, so just an offset at the end of the structure: that's why memory must be allocated manually
};

struct pls2
{
    long len;     // 8 bytes
    char str[20]; // fixed-len array, there's no more a pointer, no need to malloc/free the string
    //+ 4 bytes of padding
};

#define HEXDUMP_CHARS_PER_LINE 8
hexdump(void *p, size_t len)
{
    unsigned char *byte = p;
    size_t po = 0;
    for (size_t j = 0; j < len; j++)
    {
        printf("%02X ", byte[j]);
        if ((j + 1) % HEXDUMP_CHARS_PER_LINE == 0 || j == len - 1)
        {
            if (j == len - 1)
            {
                int pad = HEXDUMP_CHARS_PER_LINE - (len % HEXDUMP_CHARS_PER_LINE);
                pad %= HEXDUMP_CHARS_PER_LINE;
                for (int i = 0; i < pad; i++)
                {
                    printf("~~ ");
                }
            }

            printf("\t");
            for (size_t i = po; i <= j; i++)
            {
                int c = isprint(byte[i]) ? byte[i] : '.';
                printf("%c", c);
            }
            printf("\n");
            po = j + 1;
        }
    }
    printf("\n");
}

int main(void)
{
    struct pls s;
    s.len = 10;
    s.str = malloc(10 + 1);
    memcpy(s.str, "1234567890", 11);

    // the literal string will be transformed in a pointer by the compiler
    // printf("%p\n", "kashkjahkjhsaa");
    printf("%p\n", s.str);
    // 0x5bedf18712a0
    hexdump(&s, sizeof(s) + 1);
    //          len           |        pointer
    // 0A 00 00 00 00 00 00 00 A0 12 87 F1 ED 5B 00 00
    // the pointer address must be read in reverse order since this is a little-endian machine

    struct pls2 s2;
    s2.len = 10;
    // no need to allocate mem for s.str, the struct has been already allocated on the stack
    // if you want the struct to live outside main, allocating memory for the struct will allocate memory also for str
    memcpy(s2.str, "1234567890", 11);
    printf("%p\n", &s2);
    printf("%p\n", s2.str);
    hexdump(&s2, sizeof(s2));
    //test func with truncated input
    //hexdump(&s2, sizeof(s2)-3);

    struct pls2 s3;
    // set to FF all the uninitialized bytes
    memset(&s3,0xff,sizeof(s3));
    s3.len=10;
    memcpy(s3.str, "1234567890", 11);
    printf("%p\n", &s3);
    printf("%p\n", s3.str);
    hexdump(&s3, sizeof(s3));

}