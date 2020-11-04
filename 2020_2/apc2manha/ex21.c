#include <stdio.h>
#include <stdlib.h>


typedef struct aluno
{
    char nome[30];
    float n1,n2,media;
    long int matricula;
}aluno;


int main()
{
    aluno * turma;

    int qtd_alunos,i;
    int tamanho_de_aluno;

    printf("\n Qual a quantidade de alunos? ");
    scanf("%d",&qtd_alunos);

    tamanho_de_aluno = sizeof(aluno);
    turma = malloc(tamanho_de_aluno *qtd_alunos);

    for(i=0;i<qtd_alunos;i++)
    {
        turma[i].n1=1;
        turma[i].n2=2;
    }


}