#include <stdio.h>
#include <stdlib.h>

int primo(int x);
int main()
{
    int n1,n2;
    int aux;
    int i;

    printf("\n Digite n1: ");
    scanf("%d",&n1);

    printf("\n Digite n2: ");
    scanf("%d",&n2);

    if (n2 < n1)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }

    for(i=n1;i<=n2;i++)
    {
        if (primo(i))
        {
            printf("\n %d",i);
        }
    }



    return 0;
}


int primo(int x)
{
    int divisor;

    if (x==1)
    {
        return 0;
    }

    for(divisor=2;divisor<x;divisor++)
    {
        if (x%divisor==0)
        {
            return 0;
        }
    }
    return 1;
}