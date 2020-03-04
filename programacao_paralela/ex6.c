#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        printf("\n hello = %d",id);
        printf("\n world = %d",id);

    }
    printf("\n");
    return 0;
}