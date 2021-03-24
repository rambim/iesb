#include <stdio.h>
#include <stdio.h>
#include "omp.h"


int main()
{
    omp_set_num_threads(6);

    #pragma omp parallel
    {
        
        #pragma omp sections nowait
        {
            #pragma omp section
                printf("\nThread = %d Section A",omp_get_thread_num());
            #pragma omp section
                printf("\nThread = %d Section b",omp_get_thread_num());
            #pragma omp section
                printf("\nThread = %d Section c",omp_get_thread_num());
        }

        printf("\nThread = %d fora da section ", omp_get_thread_num());
    }
    return 0;
}
