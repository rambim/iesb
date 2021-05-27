// 1) Faça um programa que receba um número N inteiro positivo do usuário,
// aloque um vetor de tamanho N, preencha os N números do vetor e diga quantos primos
// há nesse vetor.


#include <stdio.h>
#include <stdlib.h>

int * aloca_vetor(int tamanho);
void preenche_vetor(int * vet, int tam);
int conta_primos(int * vet, int tam);
int primo(int x);

int main()
{
    int * vet,n,qtd_primos;

    printf("\n Digite o valor N:");
    scanf("%d",&n);

    vet = aloca_vetor(n);
    preenche_vetor(vet,n);
    qtd_primos = conta_primos(vet,n);

    printf("\nExistem %d numeros primos no vetor.",qtd_primos);

    printf("\n");
    return 0;
}

int * aloca_vetor(int tamanho)
{
    int * novo;
    novo = (int*)malloc(sizeof(int)*tamanho);
    return novo;
}

void preenche_vetor(int * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\nDigite o %d numero: ",i+1);
        scanf("%d",&vet[i]);
    }
}

int primo(int x)
{
    if (x==1||x==0)
        return 0;
    
    int div;

    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }

    return 1;
}

int conta_primos(int * vet, int tam)
{
    int i;
    int qtd=0;
    for(i=0;i<tam;i++)
    {
        if (primo(vet[i]))
            qtd++;
    }

    return qtd;
}