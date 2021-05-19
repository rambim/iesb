#include <stdio.h>
#include <stdlib.h>

void mostra_vetor(int * vet, int tam);

int main()
{
    int * vet, n,i;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    vet = (int*)calloc(n,sizeof(int));

    for(i=0;i<n;i++)
    {
        vet[i] = i+1;
    }
    mostra_vetor(vet,n);

    n = n *2;

    vet = (int*)realloc(vet,sizeof(int)*n);

    mostra_vetor(vet,n);

    printf("\n");
    
    return 0;
}

void mostra_vetor(int * vet, int tam)
{
    int i;
    printf("\nVetor:");
    for(i=0;i<tam;i++)
    {
        printf(" %d",vet[i]);
    }
    
}