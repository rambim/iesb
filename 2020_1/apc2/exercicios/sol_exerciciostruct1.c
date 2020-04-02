#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
   int matricula;
   float notas[3];

}aluno;

void LeAluno(aluno * x);
void ImprimeTurma(aluno * vet);
float CalculaMediaAluno(float * vet);

int main()
{
    int i;
    aluno Turma[5];
    float media;

    for(i=0; i< 5; i++)
    {
        LeAluno(&Turma[i]);
    }
    
    ImprimeTurma(Turma);

    for(i=0; i< 5; i++)
    {
        media = CalculaMediaAluno(Turma[i].notas);                                     
        printf("\nAluno %d  - Media = %f\n",i+1, media); 
    }
    return 0;
}

void LeAluno(aluno * x)
{
    int i;
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&x->matricula);

    for(i=0;i<3;i++)
    {
        printf("\n Digite a %d nota: ",i+1);
        scanf("%f",&x->notas[i]);
        
    }
    

}

void ImprimeTurma(aluno * vet)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("\n Matricula: %d",vet[i].matricula);

        for(j=0;j<3;j++)
        {
            printf("\n Nota %d = %f",j+1,vet[i].notas[j]);
        }

    }
    
}

float CalculaMediaAluno(float * vet )
{
    float media,sum=0;
    int i;

    for(i=0;i<3;i++)
    {
        sum = sum + vet[i];
    }
    
    media = sum/3.0;
    return media;

}
