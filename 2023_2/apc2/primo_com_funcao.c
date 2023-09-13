#include <stdio.h>
#include <stdlib.h>

int primo(int x);

int main()
{
    int i;

    for(i=1;i<100;i++)
    {
        if (primo(i)==1)
        {
            printf("%d e primo\n",i);
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
        if (x%divisor ==0)
            return 0;
    }

    return 1;
}