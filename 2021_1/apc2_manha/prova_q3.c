#include <stdio.h>
#include <stdlib.h>

int qtd_primos(int x, int y);
int primo(int x);

int main()
{
    int x,y;

    printf("\n Digite o valor de X: ");
    scanf("%d",&x);
    printf("\n Digite o valor de Y: ");
    scanf("%d",&y);

    printf("\n Existem %d numeros primos entre %d e %d",qtd_primos(x,y),x,y);
    printf("\n");
    return 0;
}

int qtd_primos(int x, int y)
{
    int aux,i;
    int qtd=0;
    if (x>y)
    {
        aux = x;
        x = y;
        y = aux;
    }

    for(i=x;i<=y;i++)
    {
        if (primo(i))
            qtd++;
    }
    return qtd;
}

int primo(int x)
{
    if ((x==1) || (x==0))
        return 0;
    int div;
    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }
    return 1;
}