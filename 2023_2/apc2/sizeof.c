#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int a;
    char b;
    char d;
    int c;

}aluno;

int main()
{

    aluno * turma;

    turma = (aluno*)malloc(sizeof(aluno) * 50);
    printf("Tamanho de aluno em bytes: %d",sizeof(aluno));
    printf("\n\n");

    turma[0].a = 10;
    
    return 0;
}