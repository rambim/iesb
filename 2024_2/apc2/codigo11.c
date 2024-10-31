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
    aluno  * ptr;

    ptr = (aluno*)malloc(sizeof(aluno));

    (*ptr).matricula = 123;
    
    ptr->matricula = 123;

    return 0;
}

void mostrar_dados_aluno(aluno a)
{
    printf("\nMatricula = %ld",a.matricula);
    printf("\nN1        = %f",a.n1);
    printf("\nN2        = %f",a.n2);
    printf("\nMedia     = %f",a.media);
}