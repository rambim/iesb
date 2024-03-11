#include <stdio.h>
#include <stdlib.h>

int teste (int x, int y);

int main()
{
    int x = 6, y = 4;
    x = teste(y,x);
    printf("\n %d", x + y);
    return 0;
}

int teste (int x, int y)
{
    x = x * 2;
    y = y * 4;
    printf("\n %d",x + y);
    return x - y;
}