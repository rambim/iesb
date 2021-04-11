#include <stdio.h>
#include <stdlib.h>

int funcao(int * x, int * y, int z);

int main()
{
    int a,b,*c,x;

    a = 2;
    b = 3;
    c = &a;

    x = funcao(&a, c, b);

    printf("%d %d %d",b,a,x);
    return 0;
}


int funcao(int * x, int * y, int z)
{
    *x = *x + 5;
    *y = *y + 7;
    z = *x + *y;
    return z;
}

