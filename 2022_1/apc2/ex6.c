#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10];

    int i;

    for(i=0;i<10;i++)
    {
        vet[i] = i + 1;
    }


    printf("\n %d",vet);
    printf("\n %d",&vet[0]);
    printf("\n");
}