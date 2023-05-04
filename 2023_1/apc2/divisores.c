#include <stdio.h>
#include <stdlib.h>

int perfeito(int x);
int main()
{
    int i;

    int qtd=0;
    int numero[10];
    int perfeitos[10] = {0};
    int maior_perfeito;
    int menor_perfeito;
    int som=0;
    for(i=0;i<10;i++)
    {
        printf("Digite um numero:\n");
        scanf("%d",&numero[i]);

        if (perfeito(numero[i])==1)
        {
            perfeitos[i] = 1;
            som = som + numero[i];


            if (qtd==0)
            {
                maior_perfeito = numero[i];
                menor_perfeito = numero[i];
            }
            else
            {
                if (numero[i] < menor_perfeito)
                {
                    menor_perfeito = numero[i];
                }
                if (numero[i] > maior_perfeito)
                {
                    maior_perfeito = numero[i];
                }
            }
            qtd++;
        }

    }

    for (i =0 ;i<10;i++)
    {
        if (perfeitos[i]==1)
        {
            printf(" O numero %d e perfeito\n",numero[i]);
        }
    }

    printf("\n Existem %d numeros perfeitos",qtd);
    printf("\n O maior numero perfeito e %d",maior_perfeito);
    printf("\n O menor numero perfeito e %d",menor_perfeito);
    printf("\n O somatorio dos numeros perfeitos e = %d",som);

    return 0;
}



int perfeito(int x)
{
    int i;

    int som=0;
    for(i= 1; i<x;i++)
    {
        if (x%i==0)
        {
            som = som + i;
        }
    }

    if (som == x)
        return 1;
    else
        return 0;

}