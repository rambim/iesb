#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void inicializa_vetor(long int * vet, long int  tam);
int validador(long int x, long int y);
int busca_linear(long int * vet,  long int tam, long int x);
int busca_binaria(long int * vet,long int inicio, long int fim, long int x);

int main()
{
    

    long int tam=1000;
    double t1,t2;    
    long int * vet;

    vet = (long int *)malloc(sizeof(long int)*tam);

    inicializa_vetor(vet,tam);


    t1 = omp_get_wtime();
    if (busca_linear(vet,tam,10))
    {
        printf("\n 10 esta no vetor");
    }
    else
    {
        printf("\n 10 nao esta no vetor");
    }
    t2 = omp_get_wtime();

    printf("\n Tempo: %f",t2-t1);

    t1 = omp_get_wtime();
    if (busca_binaria(vet,0,tam-1,10))
    {
        printf("\n 10 esta no vetor");
    }
    else
    {
        printf("\n 10 nao esta no vetor");
    }
    t2 = omp_get_wtime();

    printf("\n Tempo: %f",t2-t1);

    printf("\n");
    return 0;
}

int busca_linear(long int * vet,  long int tam, long int x)
{
    long int i;
    
    for(i=0;i<tam;i++)
    {
        if (validador(vet[i],x))
            return 1;
    }
    return 0;
}

int busca_binaria(long int * vet,long int inicio, long int fim, long int x)
{
    long long int meio;

    if (inicio>fim)
        return 0;

    meio = (inicio+fim)/2;

    if (validador(vet[meio],x))
            return 1;
    else
    {
        if (vet[meio]< x)
        {
            busca_binaria(vet,meio+1,fim,x);
        }
        else
        {
            busca_binaria(vet,inicio,meio-1,x);
        }

    }

}

void inicializa_vetor(long int * vet, long int  tam)
{
    long int i;

    for(i=0;i<tam;i++)
    {
        vet[i]=0;
    }
}




int validador(long int x, long int y)
{
    int i,j,aux=0;

    for(i=0;i<1000;i++)
    {
        for(j=0;j<10000;j++)
        {
            aux=0;
        }
    }
    return x==y ? 1 : 0;

}




