#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define tam 400

int funcao_pesada(int x);
void mostrar_vetor(int *vet, int x);

int main(int argc, char *argv[])
{
    double t1, t2;
    int i, j, vet[tam], threads_desejadas;
    int *qtd_por_thread;

    threads_desejadas = atoi(argv[1]);
    omp_set_num_threads(threads_desejadas);

    qtd_por_thread = (int *)malloc(sizeof(int) * threads_desejadas);

    for (i = 0; i < threads_desejadas; i++)
    {
        qtd_por_thread[i] = 0;
    }

    t1 = omp_get_wtime();
#pragma omp parallel for schedule(dynamic,1)
    for (i = 0; i < tam; i++)
    {
        int j, id;
        id = omp_get_thread_num();
        // printf("\nI = %d Thread = %d", i, id);

        j = 5 + 2 * (i + 1);
        vet[i] = funcao_pesada(id);
        qtd_por_thread[id]++;
    }

    t2 = omp_get_wtime();

    //mostrar_vetor(vet,tam);

    for (i = 0; i < threads_desejadas; i++)
    {
        printf("\n Thread %d processou %d iteracoes", i, qtd_por_thread[i]);
    }

    printf("\n Tempo total: %lf", t2 - t1);
    return 0;
}

int funcao_pesada(int x)
{
    // printf("\n Funcao pesada para %d ", x);
    int i, j, k;
    if (x == 0)
    {
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100; j++)
            {
                for (k = 0; k < 100; k++)
                {
                    x = x;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < 1000; i++)
        {
            for (j = 0; j < 1000; j++)
            {
                for (k = 0; k < 100; k++)
                {
                    x = x;
                }
            }
        }
    }

    
    return x;
}

void mostrar_vetor(int *vet, int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        printf("\n%d", vet[i]);
    }
    printf("\n");
}
