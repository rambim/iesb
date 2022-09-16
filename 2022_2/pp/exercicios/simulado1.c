#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void funcao_pesada();
void impares(int ini, int fim);
void par(int ini, int fim);
void primos(int ini, int fim);
int primo(int x);
int main()
{

    omp_set_num_threads(3);

    #pragma omp parallel
    {
        int id=omp_get_thread_num();
        printf("\n %d",id);

        #pragma omp sections
        {
            #pragma omp section
            {
                funcao_pesada();
                par(1,10);
                printf("\n Primeira Section pela id %d",id);
            }
            #pragma omp section
            {
                impares(1,10);
                funcao_pesada();
                printf("\n segunda Section pela id %d",id);
            }
            #pragma omp section
            {
                primos(1,10);
                funcao_pesada();
                printf("\n terceira Section pela id %d",id);
            }
        }
    }
    printf("\n");
    return 0;

}

void funcao_pesada()
{
    int i,j,z=0;

    for(i=0;i<10000;i++)
    {
        for(j=0;j<1000;j++)
        {
            z=0;
        }
    }
}

void par(int ini, int fim)
{
    int i;
    for(i=0;i<=fim;i++)
    {
        if (i%2==0)
        {
            printf("\n Par: %d",i);
        }
    }
    
}

void impares(int ini, int fim)
{
    int i;
    for(i=0;i<=fim;i++)
    {
        if (i%2!=0)
        {
            printf("\n Impares: %d",i);
        }
    }
}


void primos(int ini, int fim)
{
    int i;
    for(i=ini;i<=fim;i++)
    {
        if (primo(i))
        {
            printf("\n primo: %d",i);
        }
    }
}

int primo(int x)
{
    if (x==1)
        return 0;
    int div=2;
    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }
    return 1;
}