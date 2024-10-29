#include <stdio.h>
#include <stdlib.h>
void funcao(int a, int b);

int main()
{
    int x = 2, y = 3;

    funcao(y, x);
    printf("%d\n", x + y );

    return 0;
}

void funcao(int x, int y)
{
    x = x + 1;
    y = y + 2;
    printf("%d %d\n", x, y);
}
