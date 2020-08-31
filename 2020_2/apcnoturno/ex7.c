#include <stdio.h>
#include <stdlib.h>

int funcao(int y, int * x);

int main()
{
    int x=2,y=3,z;

    z = funcao(x,&y);

    printf("\n %d %d %d",x,y,z);
    printf("\n");
    return 0;
}

int funcao(int y, int * x)
{
    y = y + 10;
    *x = *x + 5;
    return (y + *x);
}