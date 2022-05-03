#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{

    int n;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    omp_set_num_threads(n);

    #pragma omp parallel
    {
        int id;

        id = omp_get_thread_num();

        #pragma omp single
        printf("\n Iniciando mundo paralelo");

        printf("\n Eu sou a thread %d",id);

        #pragma omp barrier

        #pragma omp master
        printf("\n FIM");
    }

    printf("\n");
    return 0;
}