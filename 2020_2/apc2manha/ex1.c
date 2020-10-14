#include <stdio.h>
#include <stdlib.h>

void funcao1(int x);

void main()
{
    int x=2;


    printf("%d ",x);
    funcao1(x);
    printf("%d",x);
    printf("\n");
    
}

void funcao1(int x)
{
    x = x + 2;
}