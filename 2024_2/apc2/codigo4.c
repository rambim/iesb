#include <stdio.h>
#include <stdlib.h>
void funcao(int a, int b);

int main()
{
    int x = 2, y = 3;

    funcao(x, y);
    printf("%d\n", x);

    return 0;
}

void funcao(int a, int b)
{
    a = a + 1;
    b = b + 2;
    printf("%d %d\n", a, b);
}
