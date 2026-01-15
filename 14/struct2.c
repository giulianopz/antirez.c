#include <stdio.h>
#include <stdlib.h>

// structs are for data that is convenient to make reside in contiguous space memory space
/*
    internal layout:
    +---+---+
    |num|den|
    +---+---+
      4B  4B
 */
struct fract
{
    // declaring here the 1-byte would cause the overall struct size to grow to 12 bytes
    // because 3 bytes of padding would be added to compensate for the small size of this field.
    // in fact, a struct size is always a multiple of its larger field
    //unsigned char color;
    int num;
    int den;
};

void *create_fraction(int num, int den)
{
    // this func could also changed to return the struct values
    // but this causes an implicit copy
    // which may not be desiderable.
    // so usually structs are returned by pointer
    struct fract *f = malloc(sizeof(struct fract));
    // it can also be written as:
    // struct fract *f = malloc(sizeof(*f));
    // libraries should perform such checks on malloc,
    // so that projects using libraries can avoid to do it
    if (f == NULL)
        return NULL;
    f->num = num;
    f->den = num;
    return f;
}

void print_fraction(struct fract *f)
{
    printf("%d/%d\n", f->num, f->den);
}

void simplify_fraction(struct fract *f)
{
    for (int d = 2; d <= f->num&& d <= f->den; d++)
    {
        while (f->num % d == 0 && f->den% d == 0)
        {
            f->num /= d;
            f->den /= d;
        }
    }
}

int main(void)
{
    printf("size of fract struct:%d \n", (int)sizeof(struct fract));

    // structs makes easier to access pieces of information that have a name
    // compared to accessing info by index in an array
    struct fract a;
    a.num = 1;
    a.den = 2;
    printf("%d %d", a.num, a.den);

    // the syntax is different with pointers to access fields
    // probably just for readability
    struct fract *b;
    b = &a;
    b->num = 1;
    b->den = 2;

    struct fract *f1 = create_fraction(1, 2);
    struct fract *f2 = create_fraction(3, 4);
    print_fraction(f1);
    print_fraction(f2);

    return 0;
}