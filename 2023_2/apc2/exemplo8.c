#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int matricula;
    float notas[10];

}aluno;

int main()
{

    aluno turma[10];
    float media,soma=0;

    int i,j;

    for(i=0;i<10;i++)
    {
        turma[i].matricula = i+1;

        for(j=0;j<10;j++)
        {
            turma[i].notas[j] = 10;
        }
    }


    for(i=0;i<10;i++)
    {
        printf("Matricula: %d\n",turma[i].matricula);
        for(j=0;j<10;j++)
        {
            printf("%d nota = %f\n",j+1,turma[i].notas[j]);
            soma = soma + turma[i].notas[j];
            
        }
        media = soma/10.0;
        printf("Media = %f",media);

        printf("\n");
    }


    return 0;
}