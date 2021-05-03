#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "omp.h"

int subset(int *vet, int n, int x, int y, int valor);
int *aloca_vetor(int tamanho);
void mostrar_vetor(int *vet, int tamanho);
int somatorio_vetor(int * vet, int tamanho);

int main()
{
    int *vet;
    int i;
    int sum;
    double t1,t2;
    int sum_vet;

    for (i = 5; i <= 40; i++)
    {
       // sum = rand() % 31;
        sum = 1;
        vet = aloca_vetor(i);
        mostrar_vetor(vet,i);
        printf("\n Verificar se existe sub set = %d",sum);
        sum_vet = somatorio_vetor(vet,i);
        t1 = omp_get_wtime();
        if (subset(vet,i,0,sum_vet,sum))
            printf("\n Existe subsetsum");
        else
            printf("\n Nao existe subsetsum");        
        t2 = omp_get_wtime();
        printf("\n Tempo gasto: %f",t2-t1);
        printf("\n");
        free(vet);
    }
    // int vet[3] = {1,3,5};

    // if (subset(vet,3,0,7,10))
    // printf("\n Existe  um subsetsum");
    // else
    // printf("\n Nao existe um subsetsum");

    printf("\n");
}

int *aloca_vetor(int tamanho)
{
    int *vet;
    int i;
    vet = (int *)calloc(tamanho, sizeof(int));

    vet[0] = 2;
    for (i = 1; i < tamanho; i++)
    {
        vet[i] = vet[i - 1] + 1 + rand() % 3;
    }

    return vet;
}

void mostrar_vetor(int *vet, int tamanho)
{
    int i;
    printf("\nVetor:");
    for (i = 0; i < tamanho; i++)
    {
        printf(" %d", vet[i]);
    }
}

int subset(int *vet, int n, int x, int y, int valor)
{
    if (n == -1)
        return 0;

    if (x + vet[n] == valor)
        return 1;

    return (subset(vet, n - 1, x + vet[n], y - vet[n], valor) || subset(vet, n - 1, x, y - vet[n], valor));
}

int somatorio_vetor(int * vet, int tamanho)
{
    int i;
    int som=0;
    for(i=0;i<tamanho;i++)
    {
        som = som + vet[i];
    }
    return som;
}

