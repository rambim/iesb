// 2)
// Faça um programa que receba do usuário um número N inteiro positivo e aloque um vetor de N números inteiros.
// Mostre na tela qual a media dos valores dentro desse vetor e quantos números primos há nesse vetor.



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa_vetor(int * vet, int tam);
void mostrar_vetor(int * vet, int tam);
float calcula_media(int * vet, int tam);
int primo(int x);
int verifica_qtd_primos(int * vet, int tam);

int main()
{
    srand(time(NULL));
    int n,qtd_primos;
    int *vet;
    float media;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    vet = (int*)malloc(sizeof(int)*n);

    inicializa_vetor(vet,n);
    mostrar_vetor(vet,n);

    media = calcula_media(vet,n);
    qtd_primos = verifica_qtd_primos(vet,n);

    printf("\nMedia dos valores do vetor: %f",media);
    printf("\nQuantidade de numeros primos: %d",qtd_primos);
    
    free(vet);

    printf("\n");
    return 0;
}

void inicializa_vetor(int * vet, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = rand() % 100;
    }
}

void mostrar_vetor(int * vet, int tam)
{
    int i;
    printf("\n Vetor:");
    for(i=0;i<tam;i++)
    {
        printf(" %d",vet[i]);
    }
}

float calcula_media(int * vet, int tam)
{
     float media,som=0;
     int i;

     for(i=0;i<tam;i++)
     {
        som = som + vet[i];  
     }

     media = som/(float)tam;
     return media;
}

int primo(int x)
{
    if ((x==1) || (x==0))
        return 0;

    int div;
    for(div=2;div<x;div++)
        if (x%div==0)
            return 0;
    return 1;
}

int verifica_qtd_primos(int * vet, int tam)
{
    int i,qtd=0;
    for(i=0;i<tam;i++)
        if (primo(vet[i]))
            qtd++;
    
    return qtd;
}




