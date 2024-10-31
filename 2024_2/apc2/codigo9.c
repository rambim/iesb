#include <stdio.h>
#include <stdlib.h>


typedef struct registro
{
    int valor;
    char letra;
    int cpf;
}registro;

int main()
{
    int * vet;
    int tamanho;
    int i;

    printf("\n DIgite o tamanho do vetor desejado: ");
    scanf("%d",&tamanho);

    vet = (int*)malloc(sizeof(int)*tamanho);

    for(i = 0 ; i <tamanho;i++)
    {
        vet[i] = 10;
    }


    for(i = 0 ; i <tamanho;i++)
    {
        printf("\n Vet[%d] = %d",i,vet[i]);
    }

    printf("\n VET = %d",vet);
    printf("\n &vet[0] = %d",&vet[0]);
    printf("\n &vet[1] = %d",&vet[1]);
    printf("\n &vet[2] = %d",&vet[2]);

    

    

    return 0;
}