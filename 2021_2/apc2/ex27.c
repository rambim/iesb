#include <stdio.h>
#include <stdlib.h>


int main()
{
    int * vet;

    vet = (int*) malloc(sizeof(int));



    printf("\n vet     : %d ",vet);
    printf("\n &vet    : %d",&vet);
    printf("\n &vet[0] : %d",&vet[0]);

    free(vet);

    return 0;
}