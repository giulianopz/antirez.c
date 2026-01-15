#include <stdio.h>
#include <stdlib.h>



void *create_fraction(int num, int den){
    int *f = malloc(sizeof(int)*2);
    // libraries should perform such checks on malloc,
    // so that projects using libraries can avoid to do it
    if (f==NULL)
        return NULL;
    f[0]=num;
    f[1]=num;
    return f;
}

void print_fraction(int *f) {
    printf("%d/%d\n", f[0],f[1]);
}

void simplify_fraction(int *f){
    for (int d = 2; d <= f[0] && d <= f[1]; d++)
    {
        while (f[0]%d==0&&f[1]%d==0){
            f[0] /= d;
            f[1] /= d;
        }
    }
}

int main(void) {
    int *f1 = create_fraction(1,2);
    int *f2 = create_fraction(3,4);
    print_fraction(f1);
    print_fraction(f2);
    return 0;
}