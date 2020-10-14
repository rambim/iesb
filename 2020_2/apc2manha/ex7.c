#include <stdio.h>
#include <stdlib.h>

void funcao1(int x);
void funcao2(int * vet , int tam);

int main()
{
    
    int x=2,i;
    int vet[3] ={1,2,3};

    funcao1(x);
    printf("\n %d",x);

    funcao2(vet,3);
    for(i=0;i<3;i++)
    {
        printf("\n%d",vet[i]);
    }
   return 0;
}

void funcao1(int x)
{
    x = 10;
}

void funcao2(int * vet , int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vet[i] = 10;
    }
}