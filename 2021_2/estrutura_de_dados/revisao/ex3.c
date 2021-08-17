#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    int idade;
    char nome[30];
}aluno;

int main()
{
    aluno a;

    a.idade = 10;
    strcpy(a.nome,"Felippe");
    printf("\n Nome do aluno: %s Idade do aluno: %d",a.nome,a.idade);
    printf("\n");

    aluno *ptr_para_aluno;

    ptr_para_aluno = &a;

    printf("\n Nome do aluno: %s Idade do aluno: %d",(*ptr_para_aluno).nome,(*ptr_para_aluno).idade);
    printf("\n Nome do aluno: %s Idade do aluno: %d",ptr_para_aluno->nome,ptr_para_aluno->idade);

    return 0;
}