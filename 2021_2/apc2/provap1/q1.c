#include <stdio.h>
#include <stdlib.h>

int perfeito(int x);

int main()
{
    int vet[10],i,qtd_perfeitos=0;
    int retorno;

    printf("\nDigite 10 numeros: ");
    
    for(i=0;i<10;i++)
    {
        scanf("%d",&vet[i]);
    }

    printf("\nPerfeitos: ");
    for(i=0;i<10;i++)
    {
        retorno = perfeito(vet[i]);
        if (retorno==1)
        {
            printf("%d ",vet[i]);
            qtd_perfeitos++;
        }

    }
    printf("\nTotal de perfeitos: %d",qtd_perfeitos);
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