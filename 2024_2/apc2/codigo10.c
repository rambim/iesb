#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float n1;
    float n2;
    float media;
    long int matricula;

}aluno;

void mostrar_dados_aluno(aluno a);
int main()
{
    aluno a;
    a.n1 = 10;
    a.n2 = 9;
    a.media = (a.n1 + a.n2) / 2.0;
    a.matricula = 123;

    mostrar_dados_aluno(a);

    return 0;
}

void mostrar_dados_aluno(aluno a)
{
    printf("\nMatricula = %ld",a.matricula);
    printf("\nN1        = %f",a.n1);
    printf("\nN2        = %f",a.n2);
    printf("\nMedia     = %f",a.media);
}