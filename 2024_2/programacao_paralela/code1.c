#include <stdio.h>
#include "omp.h"

int main()
{

    int i = omp_get_thread_num();
    printf("Hello World");

    printf("Tread = %d ",i);
    printf("\n");
    return 0;
}