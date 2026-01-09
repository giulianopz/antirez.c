#include <stdio.h>
#include <stdlib.h>

/*
    Initialize a prefixed-length string 's' with the specified string 'init' of length 'ltn'.

    WARN: this func does not check for buffer overflows.
 */
void ps_init(char *s, char *init, size_t len){
    // constrain the first byte to be a num in the positive range 0-255
    // WARN: any value beyond the upper bound will be truncated to 255
    unsigned char *lenptr= (unsigned char *) s;
    *lenptr=len;
    for (int j = 0; j < len; j++)
    {
        s[j+1]=init[j];
    }
}

/* Print out the the string 's'*/
void ps_print(char *s) {
    unsigned char *lenptr= (unsigned char *) s;
    for (int j = 0; j < *lenptr; j++)
    {
        putchar(s[j+1]);
    }
    printf("\n");
}

/*
    Initialize a prefixed-length string 's' with the specified string 'init' of length 'ltn'.

    The created strings has the following layout:
    +-+------------\\\
    |L|My string here
    +-+------------\\\

    Where L is one unsigned byte stating the total length of the string.
    Thus this string is binary safe: zero bytes are permitted in the middle.

    WARN: this func does not check for buffer overflows.
 */
char *ps_create(char *init, size_t len){
    char *s = malloc(1+len+1);
    unsigned char *lenptr= (unsigned char *) s;
    *lenptr=len;
    for (int j = 0; j < len; j++)
    {
        s[j+1]=init[j];
    }
    s[len+1]=0;
    return s;
}

// Return the pointer to the null-terminated string embedded inside our PS strinf 's'.
char *ps_getc(char *s) {
    return s+1;
}

int main(void){
    // static allocation, on the stack
    char buf[256];
    ps_init(buf, "Hello World",11);
    // we can also put a null byte in the string and this won't stop ps_print,
    // since we know the actual length of the printable string
    // ps_init(buf, "Hell\000 World",11);
    ps_print(buf);
    ps_print(buf);

    char *mystring = ps_create("Hello World", 11);
    ps_print(mystring);
    ps_print(mystring);
    printf("%s\n",mystring);
    free(mystring);
    // this chunck of memory would have been freed anyway since we are exiting the program
    return 0;
}