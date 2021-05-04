#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *aloca_vetor(long long int x);
void mostrar(long long int *vet, long long int tam);
void junta(long long *vet, long long int inicio, long long int meio, long long int fim);
void mergesort(long long int *vet, long long int inicio, long long int fim);

int main()
{
    double t1, t2;
    srand(time(NULL));
    long long int tam;
    long long int *vet;

    FILE *arq;

    arq = fopen("tempos.csv", "w");

    if (arq == NULL)
    {
        printf("\n Problemas com arquivo");
        return 0;
    }

    for (tam = 2000000; tam <= 10000000; tam = tam + 100000)
    {
        vet = aloca_vetor(tam);
        // printf("\n Desordenado: ");
        // mostrar(vet, tam);
        t1 = omp_get_wtime();
        mergesort(vet, 0,tam-1);
        t2 = omp_get_wtime();
        // printf("\n Ordenado: ");
        // mostrar(vet, tam);
        printf("\n  Tamanho %lld Tempo gasto: %f", tam, t2 - t1);
        fprintf(arq, "%lld;%f\n", tam, t2 - t1);
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

void mergesort(long long int *vet, long long int inicio, long long int fim)
{
    long long int meio;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio + 1, fim);
        junta(vet,inicio,meio,fim);
    }
    return;
}

void junta(long long *vet, long long int inicio, long long int meio, long long int fim)
{
    long long int i, j, *aux, k;

    aux = (long long int *)calloc(fim - inicio + 1, sizeof(long long int));

    i = inicio;
    j = meio + 1;
    k = 0;

    while (i <= meio && j <= fim)
    {
        if (vet[i] <= vet[j])
        {
            aux[k] = vet[i];
            k++;
            i++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
            k++;
        }
    }

    while (i <= meio)
    {
        aux[k] = vet[i];
        k++;
        i++;
    }

    while (j <= fim)
    {
        aux[k] = vet[j];
        j++;
        k++;
    }

    for(i=0;i<(fim - inicio + 1);i++)
    {
        vet[inicio+i] = aux[i];
    }
    free(aux);
    return ;
}
