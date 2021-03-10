#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{

    int nthreads;
    omp_set_num_threads(10);

    #pragma omp parallel
    {
        nthreads = omp_get_num_threads();
        int i;
        i = omp_get_thread_num();
        printf("\n Eu sou a thread: %d",i);
        
    }

    printf("\n");
    return 0;
}