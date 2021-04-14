#include <stdio.h>
#include <stdlib.h>

int funcao1(int * x, int y);
int funcao2(int y, int x);

int main()
{
    int a,b,c;
    a = 1;
    b = 2;
    c = 3;
    b = funcao1(&c,a);
    printf("\n %d %d %d ",c,b,a);
    return 0;
}

int funcao1(int * x, int y)
{
    y = funcao2(*x,y);
    printf("\n %d",* x);
    return y;
}

int funcao2(int y, int x)
{
    y = y * 2;
    x = x * 3;
    printf("%d", x+y);
    return (x * y);
}


