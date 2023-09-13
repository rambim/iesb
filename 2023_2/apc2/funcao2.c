#include <stdio.h>

int somar (int x);
int main()
{
    int x = 2;
    x = somar(x);
    printf("\n Valor de x = %d",x);
    return 0;
}

int somar (int y)
{
    y = y + 1;
    return y;
}