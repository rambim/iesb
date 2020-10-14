#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define MAX 1000000

double calculo_grande();

int main()
{
    double res[MAX];
    int i;

    #pragma omp parallel
    {
        #pragma omp for
        for (i = 0; i < MAX; i++)
        {
            res[i] = calculo_grande();
        }
    }
}

double calculo_grande()
{

    return 1;
}