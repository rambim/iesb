#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define tam 100000

int funcao_pesada(int x);

int main(int argc, char *argv[])
{
    double t1, t2;
    int i, j, vet[tam], threads_desejadas;
    long int sum = 0;

    threads_desejadas = atoi(argv[1]);
    omp_set_num_threads(threads_desejadas);

    t1 = omp_get_wtime();
    // #pragma omp parallel for 
      #pragma omp parallel for reduction (+:sum)
    for (i = 0; i < tam; i++)
    {
    
        vet[i] = funcao_pesada(1);
        sum = sum + vet[i];
    }

    t2 = omp_get_wtime();

    //mostrar_vetor(vet,tam);

    printf("\n Sum: %ld Tempo total: %lf", sum, t2 - t1);
    return 0;
}

int funcao_pesada(int x)
{
    int i, j, k;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            x = x;
        }
    }
    return x;
}