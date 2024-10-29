#include <stdio.h>
#include <stdlib.h>

void funcao();

int main()
{
    int x = 1;
    funcao(x);
    printf("%d\n",x);
    
    return 0;
}

void funcao(int x)
{
    x = x + 1;
    printf("%d\n",x);
}

