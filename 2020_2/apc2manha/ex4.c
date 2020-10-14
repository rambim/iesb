#include <stdio.h>
#include <stdlib.h>

void funcao1(int x);
int funcao2(int * x);

int main()
{
    int x=2;
    int y;

    funcao1(x);
    printf("\n%d",x);
    y = funcao2(&x);
    printf("\n%d",x);
    printf("\n");


    return 0;
}

void funcao1(int x)
{
    x = 10;
}

int funcao2(int * x)
{
    *x = 10;
    return *x;
}


