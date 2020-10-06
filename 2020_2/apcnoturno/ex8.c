#include <stdio.h>
#include <stdlib.h>

int funcao(int x, int * y);

int main()
{
    int x=10,y=10;
    int i;

    for(i=0;i<x;i++)
    {
        x = funcao(x,&y);
    }

    printf("%d",x+y);
    return 0;
}

int funcao(int x, int * y)
{
    x = x - 1;
    *y = *y + x;
    return x;
}
