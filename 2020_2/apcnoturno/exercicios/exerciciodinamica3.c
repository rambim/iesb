#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int * vet, int tam);

int main()
{
    int tam;
    int * vet;
    printf("\n Digite o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = (int*)malloc(sizeof(int)*tam);

    int i;

    preenche_vetor(vet,tam);

    printf("\n Mostrando o conteudo do vetor: ");
    for(i=0;i<tam;i++)
    {
        printf("\n%d",vet[i]);
    }


}

void preenche_vetor(int * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n Digite um valor : ");
        scanf("%d",&vet[i]);
    }
}