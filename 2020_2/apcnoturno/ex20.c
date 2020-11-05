#include <stdio.h>
#include <stdlib.h>


int main()
{
    

    int * x;

    x = (int*)malloc(4);
    x = (int*)malloc(sizeof(int));

    *x = 2;

    printf("%d",*x);
    free(x);


    int * vet;

    int qtd;

    printf("\n QUal o tamanho do vetor você deseja?: ");
    scanf("%d",&qtd);

    vet = (int*)malloc(sizeof(int)*qtd);

    int i;
    for(i=0;i<qtd;i++)
    {
        vet[i] = i;
    }

    free(vet);

    return 0;    


}