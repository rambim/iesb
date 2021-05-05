/*

Faça um programa que receba do usuário um número N inteiro positivo e aloque um vetor de N pessoas.
Cada pessoa possui nome, idade e peso
Preencha os dados das N pessoas e mostre na tela qual e a pessoa mais velha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct pessoa
{
    char nome[52];
    int idade;
    float peso;
}pessoa;

int main()
{
    int n,i;
    int indice_mais_velho=0;
    do
    {
        printf("\n Digite um numero N: ");
        scanf("%d",&n);

        if (n<0)
            printf("\n numero invalido, digite novamente");
    } while (n<0);

    pessoa * vet;

    vet = (pessoa*)malloc(sizeof(pessoa)*n);

    for(i=0;i<n;i++)
    {
        printf("\n Digite o nome: ");
        __fpurge(stdin);
        fgets(vet[i].nome,50,stdin);
        vet[i].nome[strlen(vet[i].nome)-1] = '\0';
        printf("\n Digite a idade: ");
        scanf("%d",&vet[i].idade);
        printf("\n Digite o peso: ");
        scanf("%f",&vet[i].peso);

        if (vet[i].idade > vet[indice_mais_velho].idade)
        {
            indice_mais_velho = i;
        }
    }

    printf("\n A pessoa mais velha eh %s com %d anos",vet[indice_mais_velho].nome,vet[indice_mais_velho].idade);
    
    free(vet);
    
    printf("\n");
    return 0;
}

