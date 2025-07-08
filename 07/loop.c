#include <stdio.h>


void count(int start, int end)
{
iterate:
    if (start > end)
        return;
    // the address will be the same at each 'iteration'
    printf("%d %p\n", start, &start);
    start = start +1;
    goto iterate;

    // can be rewritten as
    int i = 0; // the iteration var can be inlined in for loops, 
    // but having it declared outside loop's scope can help debugging
    while (i <10) {
	   printf("%d\n", i);
       i++;
    }
 
    // which is just as
    for (;;) {
        if (i >= 10) break;
	   printf("%d\n", i);
       i++;
    }
}

int main(void)
{
    count(0, 9);
    return 0;
}
