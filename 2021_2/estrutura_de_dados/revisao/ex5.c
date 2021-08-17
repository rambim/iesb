#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    int idade;
    char nome[30];
} aluno;

int main()
{

    aluno *ptr_de_aluno;

    ptr_de_aluno = (aluno *)calloc(10, sizeof(aluno));

    ptr_de_aluno[0].idade = 10;
    strcpy(ptr_de_aluno[0].nome,"Felippe");

    ptr_de_aluno[1].idade = 10;
    strcpy(ptr_de_aluno[1].nome,"Felippe");
    // ptr_de_aluno[1].nome[0] = "F";
    // ptr_de_aluno[1].nome[1] = "E";
    // ptr_de_aluno[1].nome[2] = "L";
    // ptr_de_aluno[1].nome[3] = "I";
    // ptr_de_aluno[1].nome[4] = "P";
    // ptr_de_aluno[1].nome[5] = "P";
    // ptr_de_aluno[1].nome[6] = "E";
    // ptr_de_aluno[1].nome[7] = "\0";

    printf("\n");
    return 0;
}