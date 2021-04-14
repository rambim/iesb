#include <stdio.h>
#include <stdlib.h>

int perfeito(int x);

int main()
{
    int vet[10],i;
    int qtd=0;

    for(i=0;i<10;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&vet[i]);
    }

    for(i=0;i<10;i++)
    {
        if (perfeito(vet[i]))
        {
            qtd++;
            printf("\nPerfeito: %d",vet[i]);
        }        
        
    }
    printf("\n Total de numeros perfeitos: %d",qtd);
    printf("\n");
    return 0;
}


int perfeito(int x)
{
    int som=0,i;
    for(i=1;i<x;i++)
    {
        if (x%i==0)
            som = som + i;
    }
    if (som==x)
        return 1;
    else
        return 0;
}