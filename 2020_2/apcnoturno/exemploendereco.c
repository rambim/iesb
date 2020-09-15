#include <stdio.h>
#include <stdlib.h>


int main()
{
    int vet[10];

    int i;

    for(i=0;i<10;i++)
    {
        vet[i] = i+1;
    }

    funcao(vet);
    return 0;
}

void funcao(int * x)
{
    printf("%d",*x);
    x[1] = 10;
}