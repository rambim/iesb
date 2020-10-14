#include <stdio.h>
#include <stdlib.h>

void funcao(int * x);
int main()
{
    int x = 2;

    printf("\n %d",x);

    funcao(&x);

    printf("\n %d",x);
    printf("\n");
    return 0;
}

void funcao(int * x)
{
    *x = 20;
}