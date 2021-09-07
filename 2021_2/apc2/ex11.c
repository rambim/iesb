#include <stdio.h>
#include <stdlib.h>

void funcao_teste(int * a);

int main()
{
    int x=2;

    funcao_teste(&x);

    printf("\n %d",x);

    printf("\n");
    return 0;
}

void funcao_teste(int * a)
{
    * a = *a * 2;
}   

