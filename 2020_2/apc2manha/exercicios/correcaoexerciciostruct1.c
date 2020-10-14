#include <stdio.h>
#include <stdlib.h>


// complete as funções restantes!

typedef struct aluno
{
   int matricula;
   float notas[3];

}aluno;
void LeAluno(aluno * joaozinho);
void ImprimeTurma(aluno * turma);
float CalculaMediaAluno (float * notas)

int main()
{
    int i;
    aluno Turma[5];
    float media;

    for(i=0; i< 5; i++)
    {
        LeAluno(&Turma[i]);
    }

    
    ImprimeTurma(&Turma[0]); 


    for(i=0; i< 5; i++)
    {
        media = CalculaMediaAluno(Turma[i].notas);// função que calcula a média das notas de um aluno
                                             
         printf("Aluno %d  - Media = %f\n",); // imprime os dados do aluno

    }
    return 0;
}

void LeAluno(aluno * joaozinho)
{
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&joaozinho->matricula);
    printf("\n Digite a n1 do aluno :");
    scanf("%f",&joaozinho->notas[0]);
    printf("\n Digite a n2 do aluno :");
    scanf("%f",&joaozinho->notas[1]);
    printf("\n Digite a n3 do aluno :");
    scanf("%f",&joaozinho->notas[2]);
}


void ImprimeTurma(aluno * turma)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("\n Matricula : %d N1: %f N2: %f N3: %f",turma[i].matricula,turma[i].notas[0],turma[i].notas[1],turma[i].notas[2]);
    }
}

float CalculaMediaAluno (float * notas)
{
    float media;
    media = (notas[0] + notas[1] + notas[2]) / 3.0;
    return media;
}
