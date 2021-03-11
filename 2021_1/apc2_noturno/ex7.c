#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 2;
    int *y;

    y = &x;

    funcao1(x);
    printf("\n %d",x);

    funcao2(y);
    printf("\n %d",x);
    return 0;
}

void funcao1 ( int x)
{
    x = x + 10;
    printf("\n %d",x);
}

void funcao2( int * x)
{
    *x = *x + 10;
}