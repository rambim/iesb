#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a = 3;
    a = funcao(a,a+1);
    printf("%d",a);
    printf("\n");
}

int funcao(int a, int b)
{
    int c;
    c = a + b;
    printf("%d %d %d ",a,b,c);
    return c;
}