#include <stdio.h>
#include <stdlib.h>


int main()
{
    int vet[5];

    printf("\n%d",vet);
    printf("\n");

    printf("\n %d ", &vet[0]);
    printf("\n %d ", &vet[1]);
    printf("\n %d ", &vet[2]);
    printf("\n %d ", &vet[3]);
    printf("\n %d ", &vet[4]);

    return 0;
}