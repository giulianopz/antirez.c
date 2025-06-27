#include <stdio.h>

int main(void)
{
    int i = 0;

again:
    printf("%d\n", i);
    i++;
    if (i < 10)
        goto again;

    // can be rewritten as:
    i = 0;
    while (i < 10)
    {
        printf("%d\n", i);
        i++;
    }

    // or
    i = 0;
loop:
    if (!(i < 10))
        goto next;
    printf("%d\n", i);
    i++;
next:

    // alternatively, we can use recursion
    count(0, 9);

    return 0;
}

void count(int start, int end)
{
    printf("%p %p\n", &start, &end);
    if (start > end)
        return;
    printf("%d\n", start);
    count(start + 1, end);
}