#include <stdio.h>
#include <stdlib.h>


int perfeito ( int x);
int main()

{
    int numero,i;
    int qtd=0;
    int maior_perfeito=0;
    int menor_perfeito=9999;
    int som=0;

    for(i=0;i<10;i++)
    {
        scanf("%d",&numero);

        if (perfeito(numero)==1)
        {
            printf("%d e perfeito\n",numero);
            qtd++;
            som = som + numero;
            if (numero > maior_perfeito)
            {
                maior_perfeito = numero;
            }
            if (numero < menor_perfeito)
            {
                menor_perfeito = numero;
            }
        }
        else
        {
            printf("%d nao e perfeito\n",numero);
        }
    }

    printf("Maior: %d\n",maior_perfeito);
    printf("Menor: %d\n",menor_perfeito);
    printf("Somatorio: %d",som);
    printf("Quantidade: %d",qtd);


    return 0;
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