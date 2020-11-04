#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

// Complexidade:
    // Melhor caso O(n)
    // Pior   caso n²

void mostrar_vetor(long int *vet, long int tam);
void bubblesort(long int *vet, long int tam);
long int *gera_vetor(long int tam);
void embaralha_vetor(long int *vet, long int tam);

int main()
{
    float t1, t2;
    long int tam;
    long int *vet;
    srand(time(NULL));
    FILE * arq;

    arq = fopen("tempos.txt","w");

    if ( arq==NULL)
    {
        printf("treta no arquivo");
        return 0;
    }


    for (tam = 10000; tam <= 150000; tam = tam + 10000)
    {
        fprintf(arq,"%ld;",tam);
        t1 = omp_get_wtime();
        vet = gera_vetor(tam);
        embaralha_vetor(vet, tam);
        t2 = omp_get_wtime();
        mostrar_vetor(vet, 10);
        printf("\nTempo total para criacao do vetor: %lf", t2 - t1);

        t1 = omp_get_wtime();
        bubblesort(vet, tam);
        t2 = omp_get_wtime();

        // printf("\n Mostrando conteudo do vetor depois de ordenar: \n");
        mostrar_vetor(vet, 10);
        fprintf(arq,"%lf\n", t2 - t1);
    }

    fclose(arq);

    return 0;
}

void mostrar_vetor(long int *vet, long int tam)
{
    long int i;
    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("%ld ", vet[i]);
    }
}

void bubblesort(long int *vet, long int tam)
{
    long int vezes, i;
    long int aux;
    int trocou=1;

    for (vezes = 0; (vezes < (tam - 1)) && trocou==1; vezes++)
    {
        trocou=0;
        for (i = 0; i < tam - 1 - vezes; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou=1;
            }
        }
    }
}

long int *gera_vetor(long int tam)
{
    long int *vet;
    long int i;
    vet = (long int *)malloc(sizeof(long int) * tam);
    for (i = 0; i < tam; i++)
    {
        vet[i] = i + 1;
    }

    return vet;
}

void embaralha_vetor(long int *vet, long int tam)
{
    long int ind_aux, aux;
    long int i;
    for (i = 0; i < tam; i++)
    {
        ind_aux = rand() % tam;

        aux = vet[i];
        vet[i] = vet[ind_aux];
        vet[ind_aux] = aux;
    }
}