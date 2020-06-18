#include  <stdio.h>
#include <stdlib.h>


int primo(int x);

int main()
{
    int N;
    int qtd_mostrados;
    int i;

    printf("\n Digite N: ");
    scanf("%d",&N);

    qtd_mostrados=0;
    i =500;
    while(qtd_mostrados<N)
    {
        if (primo(i))
        {
            printf("\n %d",i);
            qtd_mostrados++;
        }
        i++;

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