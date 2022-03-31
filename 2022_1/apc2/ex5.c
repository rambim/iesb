#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int matricula;
    float n1;
}aluno;

void mostrar_dados_aluno ( int matricula, float n1);

int main()
{
    aluno alunos[10];
    int i;


    for(i=0;i<10;i++)
    {
        alunos[i].matricula = i + 1;
        alunos[i].n1 = 10;

    }

    mostrar_dados_aluno2(alunos[0]);
    
}

void mostrar_dados_aluno ( int matricula, float n1)
{
    printf("\n Matricula do aluno: %d",matricula);
    printf("\n Nota: %f",n1);
}

void mostrar_dados_aluno2 (aluno a )
{
    printf("\n Matricula do aluno: %d",a.matricula);
    printf("\n Nota: %f",a.n1);

}