#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *aloca_vetor(long long int x);
void mostrar(long long int *vet, long long int tam);
void bubblesort(long long int *vet, long long int tam);
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

    for (tam = 10000; tam <= 150000; tam = tam + 10000)
    {
        vet = aloca_vetor(tam);
        // printf("\n Desordenado: ");
        // mostrar(vet, tam);
        t1 = omp_get_wtime();
        bubblesort(vet, tam);
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

void bubblesort(long long int *vet, long long int tam)
{
    long long int pass, i, aux;
    int trocou = 1;

    for (pass = 0; pass < tam - 1 && trocou; pass++)
    {
        trocou = 0;

        for (i = 0; i < tam - 1 - pass; i++)
        {
            if (vet[i] < vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou = 1;
            }
        }
    }
}
