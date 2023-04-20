#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[6] = {1,2,3,4,5,6};
    int * ptr;

    ptr = &vet;

    printf("\n%d",vet);
    printf("\n%d",&vet[0]);
    printf("\n%d",&vet);

    printf("\n%d", vet +  2);

    printf("\n %d",vet[1]);
    printf("\n %d",ptr[1]);

    return 0;
}