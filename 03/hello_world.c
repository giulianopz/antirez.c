#include <stdio.h>

// global var
// int x = 1;

void incr(void)
{
    // static var
    static int x = 1;
    x += 1;
    printf("%d\n", x);
}

int main(void)
{
    int a = 10;
    float y = 1.234;
    printf("%d %y\n", a, y);
    return 0;
}
