#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int funcao_pesada(int x);

int main()
{
    
    #pragma omp parallel
    {
        int x;
        int id = omp_get_thread_num();

        printf("\n ID = %d inicio ",id);

        #pragma omp single 
        {
        x = funcao_pesada(id);

        }
        
        printf("\n ID = %d fim ",id);

    }
}


int funcao_pesada(int x)
{
    printf(" \n ID = %d funcao iniciou",x);
    int i, j, k;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            x = x;
        }
    }
    printf(" \n ID = %d funcao terminou",x);
    
    return x;
}