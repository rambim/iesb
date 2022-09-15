// Gere um relatório de performance de uma solução sequencial
// e paralela para o seguinte problema:

// Mostre quais, quantos e o somatório de todos números primos entre
// 100 e 1000000000

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int funcao_pesada();
int teste(int x);
int main(int argc, char *argv[])
{

    int z;

    for (z = 1; z <= 6; z++)
    {
        int som = 0;
        double t1, t2;
        t1 = omp_get_wtime();

        omp_set_num_threads(z);

        int i;
        #pragma omp parallel for reduction(+ : som) schedule(dynamic)
        for (i = 100; i <= 1000000; i++)
        {
            // som = som + funcao_pesada();

            if (teste(i))
            {
                som = som + 1;
            }
        }

        t2 = omp_get_wtime();

        printf("\n Tempo gasto com %d threads: %lf", z, t2 - t1);
        printf("\n Somatorio: %d", som);
    }
    return 0;
}

int funcao_pesada()
{
    int i, j, z;


    for (i = 0; i < 100000; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 0; j < 10000; j++)
            {
                z = 1;
            }
        }
    }
    return 1;
}


int teste(int x)
{
    int y;
    int flag=1;
    if (x==1)
        return 0;
    #pragma omp parallel
    for(y=2;y<x && flag==1;y++)
    {
        if (x%y==0)
            #pragma omp critical
            flag=0;
    }
    if (flag==0)
        return 0;
    else
        return 1;
}