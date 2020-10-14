#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int funcao_pesada1(int x);
int funcao_pesada2(int x);
int funcao_pesada3(int x);

int main()
{
    
    #pragma omp parallel
    {
        int x;
        int id = omp_get_thread_num();

        printf("\n ID = %d inicio ",id);

        #pragma omp sections 
        {
            #pragma omp section
            x = funcao_pesada1(id);
            #pragma omp section
            x = funcao_pesada2(id);
            #pragma omp section
            x = funcao_pesada3(id);
        }

        printf("\n ID = %d fim ",id);

    }
}


int funcao_pesada1(int x)
{
    printf(" \n ID = %d funcao 1 iniciou",x);
    int i, j, k;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            x = x;
        }
    }
    printf(" \n ID = %d funcao 1 terminou",x);
    
    return x;
}
int funcao_pesada2(int x)
{
    printf(" \n ID = %d funcao 2 iniciou",x);
    int i, j, k;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            x = x;
        }
    }
    printf(" \n ID = %d funcao 2 terminou",x);
    
    return x;
}
int funcao_pesada3(int x)
{
    printf(" \n ID = %d funcao 3 iniciou",x);
    int i, j, k;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 10000; j++)
        {
            x = x;
        }
    }
    printf(" \n ID = %d funcao 3 terminou",x);
    
    return x;
}