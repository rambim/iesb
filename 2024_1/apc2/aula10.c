#include <stdio.h>
#include <stdlib.h>

int perfeito ( int x);
int main()
{
    int x;
    printf("\n Digite um numero: ");
    scanf("%d",&x);

    if (perfeito(x))
    {
        printf("\n NUmero perfeito");
    }
    else
    {
        printf("\n Numero nao e perfeito");
    }
    return 0;;
}

int perfeito ( int x)
{
    int i;
    int som=0;

    for(i=1;i<x;i++)
    {
        if (x%i==0)
        {
            som= som + i;
        }
    }

    if (som==x)
        return 1;
    else
        return 0;
}