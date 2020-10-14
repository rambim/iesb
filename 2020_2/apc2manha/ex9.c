#include <stdio.h>
#include <stdlib.h>

void preenche_celula(int * x);

int main()
{
    int vet[3]={0,0,0};
    int i;

  

    for(i=0;i<3;i++)
    {
        preenche_celula(&vet[i]);
    }

    for(i=0;i<3;i++)
    {
        printf("\n%d",vet[i]);
    }
    return 0;
}

void preenche_celula(int  * x)
{
    *x = 2;
}