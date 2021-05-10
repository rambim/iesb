/*
2) Construa uma função que receba por parâmetro um vetor e seu tamanho, e retorne 
um vetor de tamanho dobrado com os mesmos valores do vetor original. Não esqueça de
desalocara o vetor original. Na sua função principa, Aloque um vetor de tamanho N,
preencha seus N valores, e utilizando a função criada, dobre seu tamanho e solicite
ao usuário para preencher as posições restantes do vetor. Mostre o conteúdo final do vetor
dobrado.

*/

#include <stdio.h>
#include <stdlib.h>

int * dobrar_vetor(int * vet, int * tam);

int main()
{
    int * vet;
    int n,i;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    vet =(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        printf("\n Digite um valor: ");
        scanf("%d",&vet[i]);
    }

    vet = dobrar_vetor(vet,&n);

    printf("\n Vetor dobrado: ");
    for(i=0;i<n;i++)
    {
        printf(" %d",vet[i]);
        
    }



    printf("\n");
    return 0;
}


int * dobrar_vetor(int * vet, int * tam)
{
    int * novo,i;
    *tam = *tam *2;
    novo =(int*)malloc(sizeof(int)*(*tam)*2);

    for(i=0;i<(*tam)/2;i++)
    {
        novo[i] = vet[i];
    }

    free(vet);
    return novo;
}