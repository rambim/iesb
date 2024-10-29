#include <stdio.h>
#include <stdlib.h>


int main()
{

    int x,i;

    scanf("%d",&x);

    for(i=1;i<=x;i++)
    {
        if (primo(i) && primo(x-1))
        {
            printf("%d e %d", i , x-i);
        }
    }


    return 0;
}

int primo(int x)
{
    if (x == 1)
        return 0;

    int divisor;

    for(divisor=2;divisor<x;divisor++)
    {
        if (x%divisor==0)
            return 0;
    }
    return 1;
}