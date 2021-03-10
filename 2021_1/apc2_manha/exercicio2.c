#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z;
    x = 1;
    y = 2;
    z = 3;
    printf(" %d", funcao1(x,y) + funcao1(y,z));
    return 0;
}

int funcao1(int a, int b)
{
    return (a*2) + (b*3);
}

