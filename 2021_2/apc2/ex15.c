#include <stdio.h>
#include <stdlib.h>

void funcao(int x);
void funcao2(int vet[], int tam);
int main()
{

    int x = 2,i;
    int vetor[10]= {1,1,1,1,1,1,1,1,1,1};
    funcao(x);
    printf("\n %d",x);

    funcao2(vetor,10);
    funcao2(&vetor[0],10);

    vetor              [4] = 2;

    for(i=0;i<10;i++)
    {
        printf("\n -> %d",vetor[i]);
    }

    printf("\n");
    return 0;
}

void funcao(int x)
{
    x = 10;
}

void funcao2(int vet[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vet[i] = 10;
    }
}

void funcao2(int * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vet[i] = 10;
    }
}