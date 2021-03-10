#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void inicializa_vetores(long long int *vet, long long int tam, int inicio);

int main(int argc, char *argv[])
{
    int qtd_threads;
    qtd_threads = atoi(argv[1]);
    long long int *vet1, *vet2, *vet3;
    long long int tam = 10000, i;
    double t1, t2;

    printf("\n Quantidade de threads: %d", qtd_threads);

    vet1 = (long long int *)calloc(tam, sizeof(long long int));
    vet2 = (long long int *)calloc(tam, sizeof(long long int));
    vet3 = (long long int *)calloc(tam, sizeof(long long int));

    inicializa_vetores(vet1, tam, 1);
    inicializa_vetores(vet2, tam, 2);
    // int x;

    // t1 = omp_get_wtime();

    // for (i = 0; i < tam; i++)
    // {
    //     x = 1;
    //     vet3[i] = vet1[i] + vet2[i];
    // }

    // t2 = omp_get_wtime();

    // printf("\n tempo gasto sequencial : %lf", t2 - t1);
    // return 0;

    omp_set_num_threads(qtd_threads);

    t1 = omp_get_wtime();

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        long long int i;
        int x;
        int a, b;

        for (i = id; i < tam; i = i + qtd_threads)
        {
            // vet3[i] = vet1[i] + vet2[i];
            for (a = 0; a < 10000; a++)
            {
                for (b = 0; b < 50; b++)
                {
                    x = 1;
                }
            }
        }
    }

    t2 = omp_get_wtime();

    printf("\n tempo gasto com %d threads : %lf", qtd_threads, t2 - t1);

    return 0;
}

void inicializa_vetores(long long int *vet, long long int tam, int inicio)
{
    long long int i;

    for (i = 0; i < tam; i++)
    {
        vet[i] = inicio;
    }
}