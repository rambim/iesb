#include <stdio.h>
#include <stdlib.h>

typedef struct materia
{
    int codigo_materia;
    int qtd_provas;
    int codigo_professor;
    float notas[10];
    float media;

}materia;

typedef struct aluno
{
    int matricula;
    materia materias[10];
}aluno;

int main()
{
    aluno turma[3];

    int i,j,k;
    int som=0;
    for(i=0;i<3;i++)
    {
        turma[i].matricula=i+1;

        for(j=0;j<10;j++)
        {
            som = 0 ;
            turma[i].materias[j].codigo_materia = (j+1) * 10;
            turma[i].materias[j].qtd_provas = 10;
            turma[i].materias[j].codigo_professor = (j+1) * 100;

            for(k=0;k<10;k++)
            {
                turma[i].materias[j].notas[k] = 10;
                som = som + turma[i].materias[j].notas[k];
            }

            turma[i].materias[j].media = som / turma[i].materias[j].qtd_provas;
        }


    }

    for(i=0;i<3;i++)
    {
        printf("Matricula = %d\n",turma[i].matricula);
        for(j=0;j<10;j++)
        {
            printf("Cod Materia = %d Qtd Provas = %d Media = %f Cod Professor = %d\n",turma[i].materias[j].codigo_materia,turma[i].materias[j].qtd_provas, turma[i].materias[j].media,turma[i].materias[j].codigo_professor);
            for(k=0;k<10;k++)
            {
                printf("%d nota = %f\n",k+1, turma[i].materias[j].notas[k]);
            }
        }
        printf("\n");
    }
    return 0;
}