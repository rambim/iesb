#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void mergesort(long long int * vet, long long int inicio, long long int fim);
void junta(long long int * vet, long long int inicio, long long int meio, long long int fim);

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

    for (tam = 100000; tam <= 10000000; tam = tam + 100000)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        // printf("\n Vetor desordenado: ");
        // mostrar_vetor(vet, tam);
        t1 = omp_get_wtime();
        mergesort(vet, 0,tam-1);
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

void mergesort(long long int * vet, long long int inicio, long long int fim)
{
    long long int meio;

    if (inicio<fim)
    {
        meio = (inicio+fim) / 2;
        mergesort(vet,inicio,meio);
        mergesort(vet,meio+1,fim);
        junta(vet,inicio,meio,fim);
    }  
}

void junta(long long int * vet, long long int inicio, long long int meio, long long int fim)
{
    long long int i,j,*aux,k;

    aux = (long long int*)calloc(fim-inicio+1,sizeof(long long int));

    i = inicio;
    j = meio+1;
    k=0;

    while(i<=meio && j<=fim)
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            i++;
            k++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
            k++;
        }
    }

    while(i<=meio)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }

    while(j<=fim)
    {
        aux[k] = vet[j];
        j++;
        k++;
    }

    for(i=0;i<(fim-inicio+1);i++)
    {
        vet[inicio+i] = aux[i];
    }
    free(aux);
    return ;
}

