#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void selectionsort(long long int * vet, long long int tam);

int main()
{
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    double t1,t2;
    FILE * arq;

    arq = fopen("tempos.csv","a+");
    if ( arq==NULL)
        return 0;

    for (tam = 10000; tam <= 100000; tam = tam + 10000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        // printf("\n Vetor desordenado: ");
        // mostrar_vetor(vet, tam);
        t1 = omp_get_wtime();
        selectionsort(vet, tam);
        t2 = omp_get_wtime();
        printf("\n Tempo para ordenar: %f",t2-t1);
        fprintf(arq,"%lld;%f\n",tam,t2-t1);
        // printf("\n Vetor Ordenado: ");
        // mostrar_vetor(vet, tam);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *cria_vetor(long long int n)
{
    long long int *vet, i, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        sorteio = rand() % n;
        aux = vet[i];
        vet[i] = vet[sorteio];
        vet[sorteio] = aux;
    }
    return vet;
}

void mostrar_vetor(long long int *vet, long long int tam)
{
    long long int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}


void selectionsort(long long int * vet, long long int tam)
{
    long long int ind_menor, i, j,aux;

    for(i=0;i<tam-1;i++)
    {
        ind_menor = i;
        for(j=i+1;j<tam;j++)
        {
            if (vet[j] < vet[ind_menor])
            {
                ind_menor = j;
            }
        }
        aux = vet[ind_menor];
        vet[ind_menor] = vet[i];
        vet[i] = aux;
    }
}
