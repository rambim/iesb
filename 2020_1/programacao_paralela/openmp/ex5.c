#include <stdio.h>
#include <stdlib.h>


int main()
{
    #pragma omp parallel
    {
        int id =0;

        printf("\n hello = %d",id);
        printf("\n world = %d",id);

    }
    printf("\n");
    return 0;
}