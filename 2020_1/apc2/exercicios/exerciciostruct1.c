#include <stdio.h>
#include <stdlib.h>


// complete as funções restantes!

typedef struct aluno
{
   int matricula;
   float notas[3];

}aluno;

int main()
{
    int i;
    aluno Turma[5];

    for(i=0; i< 5; i++)
    {
        // LeAluno(.......);  // função que lê de teclado
        //                    // os dados do aluno

    }

    
    // ImprimeTurma(Turma); Função que imprime os dados de todos os alunos


    for(i=0; i< 5; i++)
    {
        // media = CalculaMediaAluno(.......);// função que calcula a média das notas de um aluno
                                             
        printf("Aluno %d  - Media = %f\n"); // imprime os dados do aluno

    }
    return 0;
}