#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{
    omp_set_num_threads(6);
    int vet[6][100];
    int i,j,x;

    #pragma omp parallel for collapse(2) 
    for(i=0;i<6;i++)
    {
        for(j=0;j<100;j++)
        {
            x = x;
        }
    }
    return 0;
}