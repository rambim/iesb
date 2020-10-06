#include <stdio.h>
#include <stdlib.h>


void funcao1(int x);
void funcao2(int * x);
int main()
{
    int x, *y;
    x = 5;
    printf("\n %d",x);
    funcao1(x);
    printf("\n %d",x);
    printf("\n");
    return 0;
}

void funcao1(int x)
{
    x = x + 1;
    funcao2(&x);
    printf("\n %d",x);
}

void funcao2(int * x)
{
    *x = * x + 1;
}