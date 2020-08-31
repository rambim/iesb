#include <stdio.h>
#include <stdlib.h>

void funcao1(int x);
int main()
{
    int x=2;
    printf("\n%d",x);
    funcao1(x);
    printf("\n%d",x);
    printf("\n");
    return 0;
}

void funcao1(int x)
{
    x = 10;
    printf("\n%d",x);
}


