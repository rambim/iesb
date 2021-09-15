#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int matricula;
    int idade;
    float media;

} aluno;

int main()
{
    int a;
    float b;
    aluno c;

    c.idade = 10;
    c.matricula= 20;
    c.media= 10;

    mostrar_dados_aluno(c.matricula,c.idade,c.media);
    mostrar_dados_aluno2(c);
    zerar_aluno(&c);

    printf("\n");
    return 0;
}

void mostrar_dados_aluno( int matricula, int idade, float media)
{
    printf("\n Matricula : %d",matricula);
    printf("\n Matricula : %d",idade);
    printf("\n Matricula : %f",media);
}

void mostrar_dados_aluno2(aluno a)
{
    printf("\n Matricula : %d",a.matricula);
    printf("\n Matricula : %d",a.idade);
    printf("\n Matricula : %f",a.media);
}

void zerar_aluno(aluno * a)
{
    (*a).idade = 0;
    (*a).matricula = 0;
    (*a).media = 0;
}