#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float n1,n2,media;
    long int matricula;

}aluno;

int main()
{
    int i;
    aluno turma[3];

    for(i=0;i<3;i++)
    {
        printf("\n Digite a nota 1 do %d aluno: ",i+1);
        scanf("%f",&turma[i].n1);
        printf("\n Digite a nota 2 do %d aluno: ",i+1);
        scanf("%f",&turma[i].n2);
        turma[i].media = (turma[i].n1 + turma[i].n2) / 2;
        printf("\n Digite a matricula do %d aluno: ",i+1);
        scanf("%ld",&turma[i].matricula);

    }

    for(i=0;i<3;i++)
    {
        printf("\n Aluno %ld",turma[i].matricula);
        printf(" Nota 1 = %f Nota 2 = %f Media = %f",turma[i].n1,turma[i].n2,turma[i].media);
    }
    
    printf("\n");
    return 0;
}

