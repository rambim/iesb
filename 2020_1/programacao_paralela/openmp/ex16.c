#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define TAM 1000


int main()
{
    int a[TAM], b[TAM], c[TAM];
    int i;

   
    #pragma omp parallel
    {
         int id, i, Nthrds, istart, iend; 

        id = omp_get_thread_num();
        Nthrds=omp_get_num_threads();
        istart = id * TAM / Nthrds;
        iend   = (id+1) * TAM / Nthrds;
        if (id==Nthrds-1)
        {
            iend = TAM;
        }
        for(i=istart;i<iend;i++)
        {
            c[i] = a[i] + b[i];
        }
    }

    return 0;
}
