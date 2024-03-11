#include <stdio.h>
#include <stdlib.h>

int funcao(int x, int y);
int funcao2(int y, int x);
int main()
{
    printf("\n %d ",funcao(1,3));
    return 0;
}

int funcao(int x, int y)
{
    x = funcao2(y,x);
    y = funcao2(x,y);
    return x + y;
}

int funcao2(int y, int x)
{
    x = x + 1;
    y = y + 2;
    return x * y;
}