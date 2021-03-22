/*
4)Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os
endereçosde duas variáveis inteiras, digamos min e max, e deposite nessas
variáveis ovalor de um elemento mínimo e o valor de um elemento máximo do
vetor.Escreva também uma função main que use a função mm

*/


#include <stdio.h>
#include <stdio.h>

void mm(int * vet, int tam, int * min, int * max);

int main(int argc, char * argv[])
{
    int vet[10],i,min,max;
    printf("\n Digite 10 numeros:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&vet[i]);
    }

    mm(vet,10,&min,&max);

    printf("\n O maior numero do vetor e %d e o menor e %d",max,min);
    printf("\n");
    return 0;
}

void mm(int * vet, int tam, int * min, int * max)
{
    int i;

    *min = vet[0];
    *max = vet[0];

    for(i=1;i<tam;i++)
    {
        if (vet[i] > *max)
        {
            *max = vet[i];
        }
        if (vet[i] < *min)
        {
            *min = vet[i];
        }
    }
}   
