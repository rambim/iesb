#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd,i;
    int *vet;

    printf("\nQual a quantidade de inteiros deseja alocar? ");
    scanf("%d",&qtd);

    vet = malloc(qtd * 4);

    for(i=0;i<qtd;i++)
    {
        vet[i] = i+1;
    }

    

    return 0;
}