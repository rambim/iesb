#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    omp_set_num_threads(10);
#pragma omp parallel
    {
        int i;

        #pragma omp master
        printf("\n eu sou a feroz! %d",omp_get_thread_num());

        #pragma omp barrier
        printf("\n Hello world! id = %d", omp_get_thread_num());
    }
    return 0;
}
