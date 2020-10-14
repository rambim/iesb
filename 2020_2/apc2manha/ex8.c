#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[3] = {1,2,3};
    int i;

    funcao1(vet[2]);
    funcao2(&vet[2]);

    for(i=0;i<3;i++)
    {
        printf("\n %d",vet[i]);
    }

    printf("\n");
    return 0;    
}

void funcao2(int * x)
{
    *x= 20;
}

void funcao1(int x)
{
    x = 10;
}


