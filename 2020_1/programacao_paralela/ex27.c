#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()
{
    omp_set_dynamic(0);
    omp_set_num_threads(omp_get_num_procs());

    return 0;
}