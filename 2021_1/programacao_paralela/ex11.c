#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{

    omp_set_num_threads(6);

    #pragma omp parallel 
    {

        int i;

        #pragma omp master
        {
            printf("\n Eu sou a master = %d",omp_get_thread_num());
        }


        printf("\n eu sou a thread %d",omp_get_thread_num());
        
    }
    
}

void carregar_variaveis_ambiente()
{
    return ;
}

