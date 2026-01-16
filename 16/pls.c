#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct pls
{
    uint32_t len;
    uint32_t refcount;
// could be enabled/disabled with a macro
//#ifdef PLS_DEBUG
    uint32_t magic;
//#endif
    char str[]; // C99 declaration for a pointer to a char array of undefined length
};

/*
    Initialize a prefixed-length string 's' with the specified string 'init' of
    length 'ltn'.

    The created strings has the following layout:
    +----+----+------------\\\
    |LLLL|CCCC|My string here
    +----+----+------------\\\

    Where LLLL are 4 unsigned bytes  stating the total length of the string.
    Thus this string is binary safe: zero bytes are permitted in the middle.

    WARN: this func does not check for buffer overflows.
 */
char *ps_create(char *init, size_t len)
{
    struct pls *p = malloc(sizeof(struct pls) + len + 1);
    p->len = len;
    p->refcount = 1;
    p->magic = 0xDEADBEEF;
    for (int j = 0; j < len; j++)
    {
        p->str[j] = init[j]; // TODO: use memcpy()
    }
    p->str[len] = 0;
    return p->str;
}

/* Print out the the string 's'*/
void ps_print(char *s)
{
    struct pls *p = (struct pls *)(s - sizeof(*p));
    for (int j = 0; j < p->len; j++)
    {
        putchar(p->str[j]);
    }
    printf("\n");
}

// Free a previously created PS string
void ps_free(char *s)
{
    free(s - sizeof(struct pls));
}

// Validate that a PS string looks valid
void ps_validate(struct pls *p) {
    if (p->magic!= 0xDEADBEEF) {
        printf("IVALID STRING: Aborting\n");
        exit(1);
    }
}

// Drop the ref count of the string object by one and frees the obj if ref count reaches 0
void ps_release(char *s)
{
    struct pls *p = (struct pls *)(s - sizeof(*p));
    ps_validate(p);

    p->refcount--;
    if (p->refcount == 0)
    {
        p->magic = 0;
        ps_free(s);
    }
}

// Icrease the ref count of the string obj by one
void ps_retain(char *s)
{
    struct pls *p = (struct pls *)(s - sizeof(*p));
    if (p->refcount == 0)
    {
        printf("ABORTED ON RETAIN OF ILLEGAL STRING\n");
        exit(1);
    }
    p->refcount++;
}

// Return the legth of  the string O(1) time.
uint32_t ps_len(char *s)
{
    struct pls *p = (struct pls *)(s - sizeof(*p));
    return p->len;
}

char *global_string;

int main(void)
{
    char *mystr = ps_create("Hello World", 11);
    global_string = mystr;
    ps_retain(mystr);

    ps_print(mystr);
    ps_print(mystr);
    printf("%s %d\n", mystr, (int)ps_len(mystr));
    ps_release(mystr);
    printf("%s\n", global_string);
    ps_release(mystr);

    // will cause a fatal error since the magic value was canceled out
    // ps_release(mystr);

    // would prints out garbage
    // printf("%s\n", global_string);

    // the ref counting mechanism allows us to use less calls to malloc & free
    // though the memory is still managed manually

    return 0;
}
