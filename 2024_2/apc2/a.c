#include <stdio.h>
#include <stdlib.h>

int muda (int * x, int y);
int main()
{
    int x = 5, y = 4,i;
    for(i=0;i<x + y; i++)
    {
        y = muda(&x,y);
    }
    printf("%d %d ", y, x + y);
}

int muda (int * x, int y)
{
    *x = *x - (y - 1);
    y--;
    return y;
}