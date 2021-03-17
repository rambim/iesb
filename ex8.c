/*

TECNICAS DE SINCRONIZAÇÃO

    A) BARREIRA


resultado: 
0 150
 1 210
 2 270
 3 330
 4 390
 5 450



*/

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int calculo_pesado1(int x);
int calculo_pesado2(int *vet, int tam, int x);

int main()
{
    int a[6], b[6], i;

    omp_set_num_threads(6);

#pragma omp parallel
    {
        int id,i;
        id = omp_get_thread_num();
        for (i = id; i < 6; i = i + 6 )
        {
            a[i] = calculo_pesado1(i);
        }

        #pragma omp barrier
        
        for (i = id; i < 6; i = i + 6 )
        {
            b[i] = calculo_pesado2(a, 6, i);
        }
    }

    for (i = 0; i < 6; i++)
    {
        printf("\n %d %d", a[i], b[i]);
    }
}

int calculo_pesado1(int x)
{
    int i, j;
    int resultado;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            resultado = x;
        }
    }

    return resultado;
}

int calculo_pesado2(int *vet, int tam, int x)
{
    int i, j;
    int resultado=0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < tam; j++)
        {
            resultado = resultado + vet[j] + x;
        }
    }

    return resultado;
}