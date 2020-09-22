#include <stdio.h>
#include <stdlib.h>

// complete as funções restantes!

typedef struct aluno
{
    int matricula;


    float notas[3];

} aluno;
void LeAluno(aluno *dados_de_um_aluno);
void ImprimeTurma(aluno *turma);
float CalculaMediaAluno1(float a, float b, float c);
float CalculaMediaAluno2(float * notas);
float CalculaMediaAluno3(aluno x);

int main()
{
    int i;
    aluno Turma[5];
    float media;

    for (i = 0; i < 5; i++)
    {
        LeAluno(&Turma[i]); // função que lê de teclado
    }

    ImprimeTurma(Turma);

    printf("\n Mostrando medias:\n");
    for (i = 0; i < 5; i++)
    {
        // media = CalculaMediaAluno1(Turma[i].notas[0],Turma[i].notas[1],Turma[i].notas[2]);
        media = CalculaMediaAluno2(Turma[i].notas);
        // media = CalculaMediaAluno3(Turma[i]);

        printf("Aluno %d  - Media = %f\n",i+1,media); // imprime os dados do aluno
    }
    
    printf("\n");
    return 0;
}

void LeAluno(aluno *dados_de_um_aluno)
{
    printf("\n Digite a matricula do aluno: ");
    scanf("%d", &dados_de_um_aluno->matricula);
    printf("\n Digite a n1: ");
    scanf("%f", &dados_de_um_aluno->notas[0]);
    printf("\n Digite a n2: ");
    scanf("%f", &dados_de_um_aluno->notas[1]);
    printf("\n Digite a n3: ");
    scanf("%f", &dados_de_um_aluno->notas[2]);
}

void ImprimeTurma(aluno *turma)
{
    int i;
    printf("\n TURMA: \n");
    for (i = 0; i < 5; i++)
    {
        printf("\n Matricula : %d N1: %f N2: %f N3: %f", turma[i].matricula, turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]);
    }
}

float CalculaMediaAluno1(float a, float b, float c)
{
    return (a+b+c)/3.0;

}

float CalculaMediaAluno2(float * notas)
{
    return (notas[0]+notas[1]+notas[2])/3.0;
}

float CalculaMediaAluno3(aluno x)
{
    return (x.notas[0] + x.notas[1] + x.notas[2])/3.0;
}
