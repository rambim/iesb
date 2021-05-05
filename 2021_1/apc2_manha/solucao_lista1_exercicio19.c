#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct pessoa
{
    int idade;
    char nome[30];
} pessoa;

int preenche_pessoas(pessoa *vet, int tam);
void bubblesort(pessoa * vet, int tam);
void mostrar(pessoa *vet, int tam);

int main()
{
    pessoa pessoas[10];
    int n;

    int vetor[n];

    if (preenche_pessoas(pessoas, 10))
    {
        bubblesort(pessoas,10);
        mostrar(pessoas,10);
    }
    else
    {
        printf("\n Idade negativa digitada, encerrando programa");
    }
    

    printf("\n");
    return 0;
}

int preenche_pessoas(pessoa *vet, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n Digite o nome da pessoa: ");
        __fpurge(stdin);
        fgets(vet[i].nome, 28, stdin);
        vet[i].nome[strlen(vet[i].nome) - 1] = '\0';
        printf("\n Digite a idade da pessoa: ");
        scanf("%d", &vet[i].idade);
        if (vet[i].idade < 0)
            return 0;
    }
    return 1;
}
void mostrar(pessoa *vet, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n Nome:%s Idade: %d ",vet[i].nome,vet[i].idade);
    }
}

void bubblesort(pessoa * vet, int tam)
{
    int pass,i;
    pessoa aux;
    for(pass=0;pass<tam-1;pass++)
    {
        for(i=0;i<tam-1-pass;i++)
        {
            if (vet[i].idade > vet[i+1].idade)
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
}