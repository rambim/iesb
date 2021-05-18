#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *aloca_vetor(long long int x);
void mostrar(long long int *vet, long long int tam);
void bubblesort(long long int *vet, long long int tam);
void quicksort(long long int * vet, long long int inicio, long long int fim);

int main()
{
    double t1, t2;
    srand(time(NULL));
    long long int tam;
    long long int *vet;

    FILE * arq;

    arq = fopen("tempos.csv","w");

    if (arq==NULL)
    {
        printf("\n Problemas com arquivo");
        return 0;
    }

    for (tam = 1000000; tam <= 10000000; tam = tam + 1000000)
    {
        vet = aloca_vetor(tam);
        // printf("\n Desordenado: ");
        // mostrar(vet, tam);
        t1 = omp_get_wtime();
        quicksort(vet,0,tam-1);
        t2 = omp_get_wtime();
        // printf("\n Ordenado: ");
        // mostrar(vet, tam);
        printf("\n  Tamanho %lld Tempo gasto: %f",tam, t2 - t1);
        fprintf(arq,"%lld;%f\n",tam, t2 - t1);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *aloca_vetor(long long int x)
{
    long long int *vetor;
    vetor = (long long int *)calloc(x, sizeof(long long int));
    long long int i, sorteado, aux;

    for (i = 0; i < x; i++)
    {
        vetor[i] = i + 1;
    }

    for (i = 0; i < x; i++)
    {
        sorteado = rand() % x;
        aux = vetor[i];
        vetor[i] = vetor[sorteado];
        vetor[sorteado] = aux;
    }
    return vetor;
}

void mostrar(long long int *vet, long long int tam)
{
    int i;

    printf("\n Vetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}



void quicksort(long long int * vet, long long int inicio, long long int fim)
{
    if (inicio>=fim)
    {
        return;
    }

    long long int pivo,aux,aux_troca;

    pivo = inicio;
    aux = fim;

    while(pivo!=aux)
    {
        if (pivo<aux)
        {
            if (vet[pivo]>vet[aux])
            {
                aux_troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = aux_troca;
                aux_troca = pivo;
                pivo = aux;
                aux = aux_troca;
            }
        } 
        else
        {
            if (vet[pivo]<vet[aux])
            {
                aux_troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = aux_troca;
                aux_troca = pivo;
                pivo = aux;
                aux = aux_troca;
            }

        }

        if (pivo<aux)
        {
            aux --;
        }
        else
        {
            aux ++;
        }
    }

    quicksort(vet,inicio,pivo-1);
    quicksort(vet,pivo+1,fim);

}
