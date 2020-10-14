#include <stdio.h>
#include <stdlib.h>
#include "omp.h"



int main()
{
    int aux;


    omp_set_dynamic(0);
    // omp_set_num_threads(omp_get_num_procs());
    omp_set_num_threads(6);

    aux = 1;

    #pragma omp parallel 
    {

            printf("ID = %d antes  AUX = %d\n",omp_get_thread_num(),aux);
            aux = 2;
            printf("ID = %d depois AUX = %d\n",omp_get_thread_num(),aux);

    }

    printf("Valor final de aux sem private = %d\n",aux);

    printf("\n");
    
    aux = 1;       



    #pragma omp parallel firstprivate(aux)
    {

            
            printf("ID = %d antes  AUX = %d\n",omp_get_thread_num(),aux);
            aux = 2;
            printf("ID = %d depois AUX = %d\n",omp_get_thread_num(),aux);
    }

    printf("Valor final de aux com private = %d\n",aux);
    return 0;
}