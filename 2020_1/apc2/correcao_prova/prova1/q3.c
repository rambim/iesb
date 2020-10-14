#include <stdio.h>
#include <stdlib.h>

int primo(int x);

int main()
{
    int N;
    int encontrou,i,j;
    int retorno;

    printf("\n Digite N: ");

    do
    {
        scanf("%d",&N);
        if (N<=4)
        {
            printf("\n Numero menor que 4, digite novamente: ");
        }
    } while (N<=4);



    // 1 = verdade;
    // 0 = falso;

    encontrou=0;
    i = 1;

//  while(!encontrou)
    while(encontrou == 0)
    {
        
        i++;
        if (primo(i))
        {
            j = N - i;
            if (primo(j))
            {
                encontrou=1;
            }
        }
    }

    printf("\n P1: %d  e P2: %d",i,j);
    printf("\n");

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