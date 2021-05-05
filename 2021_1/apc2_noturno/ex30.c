#include <stdio.h>
#include <stdlib.h>


typedef struct registro
{
    int x;
    double y;
    char nome[52];
    float media;
    float peso;
    long long int matricula;
}registro;

int main()
{

    int *x;
    int i=0;
    int tam;

    printf("\n Digite o tamanho do vetor: ");
    scanf("%d",&tam);

    x = (int*)calloc(1,sizeof(int));

    for(i=0;i<tam;i++)
    {
        printf("%d",x[i]);
    }


   

    printf("\n");
    return 0;
}