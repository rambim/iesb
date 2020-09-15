#include <stdio.h>
#include <stdlib.h>



// complete as funções restantes!

typedef struct aluno
{
   int matricula;
   float notas[3];

}aluno;
void LeAluno(aluno * dados_de_um_aluno);

int main()
{
    int i;
    aluno Turma[5];

    for(i=0; i< 5; i++)
    {
        LeAluno(&Turma[i]);  // função que lê de teclado
    }

    
    // ImprimeTurma(&Turma[0]); Função que imprime os dados de todos os alunos


    for(i=0; i< 5; i++)
    {
        // media = CalculaMediaAluno(.......);// função que calcula a média das notas de um aluno
                                             
        printf("Aluno %d  - Media = %f\n"); // imprime os dados do aluno

    }
    return 0;
}


void LeAluno(aluno * dados_de_um_aluno)
{
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&dados_de_um_aluno->matricula);
    printf("\n Digite a n1: ");
    scanf("%f",&dados_de_um_aluno->notas[0]);
    printf("\n Digite a n2: ");
    scanf("%f",&dados_de_um_aluno->notas[1]);

}

// ImprimeTurma(Turma); Função que imprime os dados de todos os alunos