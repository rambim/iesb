#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int * vet, int tam);
void mostrar_vetor(int * vet, int tam);

int main()
{
    int tamanho_do_vetor;

    int * vet,*vet2;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d",&tamanho_do_vetor);

    vet = (int*)malloc(sizeof(int)*tamanho_do_vetor);

    preenche_vetor(vet,tamanho_do_vetor);
    mostrar_vetor(vet,tamanho_do_vetor);


    vet2 = (int*)realloc(vet,sizeof(int)*3); 
    free(vet);

    int z=2;
    preenche_vetor(vet,tamanho_do_vetor);
    mostrar_vetor(vet,tamanho_do_vetor);
    mostrar_vetor(vet2,tamanho_do_vetor);
    return 0;

}

void preenche_vetor(int * vet, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = i;
    }
}
void mostrar_vetor(int * vet, int tam)
{
    int i;

    printf("\n Mostrando vetor: ");
    for(i=0;i<tam;i++)
    {
        printf(" %d",vet[i]);
    }
}