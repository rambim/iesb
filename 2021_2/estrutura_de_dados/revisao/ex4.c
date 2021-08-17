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

    aluno * ptr_de_aluno;

    ptr_de_aluno = (aluno*)calloc(1,sizeof(aluno));

    ptr_de_aluno->idade = 10;
    strcpy(ptr_de_aluno->nome,"Felippe");

    printf("\n Nome: %s idade: %d",ptr_de_aluno->nome,ptr_de_aluno->idade);

    printf("\n");
    return 0;
}