#include <stdio.h>
#include <stdlib.h>



int fun1(int x, int y)
{
    return x + y;
}

int fun2(int x, int y)
{
    return x*y;
}

int fun3(int a, int b)
{
    return a-b;
}

int fun4(int a)
{
    return 2*a;
}

int main()
{
    int o = 75;
    int p = 32;

    int r = fun4(fun1(fun2(o,p),fun3(p,o)));
    printf("resultado = %d",r);
}