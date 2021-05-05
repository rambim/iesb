/*
Faça uma função que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma função que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa também uma
função que receba um ponteiro para um vetor e libere esta área de memória. Ao final,
crie uma função principal que leia um valor n e chame a função criada acima. Depois,
a função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação.
*/
#include <stdio.h>
#include <stdlib.h>

int * aloca_vetor(int tamanho);
void desaloca( int * vet);
void mostrar( int * vet, int tam);

int main()
{
    int * vet;
    int n,i;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);
    vet = aloca_vetor(n);

    for(i=0;i<n;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&vet[i]);
    }

    mostrar(vet,n);
    desaloca(vet);
    printf("\n");
    return 0;
}

int * aloca_vetor(int tamanho)
{
    int * novo;
    novo = (int*)malloc(sizeof(int)*tamanho);
    return novo;
}

void desaloca( int * vet)
{
    free(vet);
}


void mostrar( int * vet, int tam)
{
    int i;
    printf("\n Vetor: ");
    for(i=0;i<tam;i++)
    {
        printf(" %d",vet[i]);
    }
}