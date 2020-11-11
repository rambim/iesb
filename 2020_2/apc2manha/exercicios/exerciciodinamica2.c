#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int * vet, int tam);

int main()
{
    int n,*vet;
    

    printf("\n Digite N: ");
    scanf("%d",&n);

    vet = (int*)malloc(sizeof(int)*n);

    preenche_vetor(vet,n);

    int i;

    printf("\n Mostrando o vetor alocado: ");
    for(i=0;i<n;i++)
    {
        printf("\n%d",vet[i]);
    }


    printf("\n");
    return 0;
}

void preenche_vetor(int * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n Digite um valor: ");
        scanf("%d",&vet[i]);
    }
}