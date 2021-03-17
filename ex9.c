/* 

TECNICAS DE SINCRONIZAÇÃO 


B ) EXCLUSÃO MÚTUA ( CRITICAL )

resultado 15;

*/

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int calculo_1(int x);
int main()
{
    int aux, i, resultado = 0;

    omp_set_num_threads(6);

    #pragma omp parallel
    {
        int i, id, aux;
        id = omp_get_thread_num();
        for (i = id; i < 6; i = i + 6)
        {
            aux = calculo_1(i);
            #pragma omp critical
            {
                resultado = resultado + aux;
            }
        }
    }

    printf("%d\n", resultado);
}

int calculo_1(int x)
{
    return x;
}