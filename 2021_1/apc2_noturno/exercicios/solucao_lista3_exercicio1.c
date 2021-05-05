#include <stdio.h>
#include <stdlib.h>


/*
Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada. 
*/

void preenche_vetor(int * vet, int tam);
int main()
{
    int n;
    int *vet;
    int i;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    vet = (int*)malloc(sizeof(int)*10);
    preenche_vetor(vet,n);

    printf("\n Vetor: ");
    for(i=0;i<n;i++)
    {
        printf(" %d",vet[i]);
    }

    free(vet);
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