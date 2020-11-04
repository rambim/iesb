/*

Faça um programa que recebe um número N inteiro positivo do usuário, aloque um vetor de N alunos, 
solicite ao usuário que preencha os dados dos N alunos e mostre o conteúdo dos N alunos na tela.
O aluno é composto por nome,idade e media;

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct aluno
{
    char nome[50];
    int idade;
    float media;
}aluno;

void preenche_aluno ( aluno * a);
void mostrar_turma(aluno * turma, int qtd);

int main()
{
    int n;
    aluno * vet;
    int i;

    do
    {
        printf("\nDigite um numero N: ");
        scanf("%d",&n);

        if (n<=0)
        {
            printf("\n Digite um N valido");
        }
    } while (n<=0);

    vet = malloc(sizeof(aluno)*n);

    for(i=0;i<n;i++)
    {
        preenche_aluno(&vet[i]);
    }
    
    mostrar_turma(vet,n);

    free(vet);

    return 0;
}

void preenche_aluno ( aluno * a)
{
    printf("\nDigite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a->nome,30,stdin);
    a->nome[strlen(a->nome)-1] = '\0';
    printf("\nDigite a idade do aluno: ");
    scanf("%d",&a->idade);
    printf("\nDigite a media do aluno: ");
    scanf("%f",&a->media);
}

void mostrar_turma(aluno * turma, int qtd)
{
    int i;

    for(i=0;i<qtd;i++)
    {
        printf("\n Nome: %s Idade: %d Media %f",turma[i].nome,turma[i].idade,turma[i].media);
    }
}