#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int idade;
    char nome[30];
} aluno;

int main()
{
    int qtd_de_alunos;
    aluno * turma;

    printf("\nDigite a quantide de alunos: ");
    scanf("%d",&qtd_de_alunos);

    turma = aloca_turma(qtd_de_alunos);
    
    printf("\n");
    return 0;
}

aluno * aloca_turma(int tamanho_da_turma)
{
    aluno * novo;
    novo = (aluno*)calloc(tamanho_da_turma,sizeof(aluno));
    return novo;
}