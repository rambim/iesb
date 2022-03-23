#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{

    double t1,t2;
    omp_set_num_threads(10000);

    int nthreads;

    t1 = omp_get_wtime();
    #pragma omp parallel
    {
        nthreads = omp_get_num_threads();
        int i;
        i = omp_get_thread_num();
        printf("\n Eu sou a thread: %d",i);
        
    }
    t2 = omp_get_wtime();

    printf("\n Numero total de threads: %d",nthreads);

    printf("\n Tempo total :%lf",t2-t1);

    printf("\n");
    return 0;
}