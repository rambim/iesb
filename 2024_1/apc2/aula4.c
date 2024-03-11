#include <stdio.h>
#include <stdlib.h>

void teste (int x, int y);

int main()
{
    int x = 2, y = 4;
    teste(y,x);
    printf("\n %d", x + y);
    return 0;
}

void teste (int x, int y)
{
    x = x * 2;
    y = y * 4;
    printf("\n %d",x + y);
}