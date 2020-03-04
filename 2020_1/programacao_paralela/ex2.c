#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    int i, x;
    omp_set_num_threads(10);

    i = omp_get_thread_num();
    printf("\nhello  world 1 =  %d", i);

    x = 2;

    #pragma omp parallel

    {
        int nthreads;

        nthreads = omp_get_num_threads();

        printf("\nNumero de threads = %d", nthreads);

        int i;
        i = omp_get_thread_num();
        printf("\nhello world 2 = %d  x = %d", i, x);
    }

    i = omp_get_thread_num();

    printf("\n hello world 3 = %d", i);
    printf("\n");
    return 0;
}
