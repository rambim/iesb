#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct aluno
{
    char nome[100];
    int matricula;
    float * notas;
    float media;
}aluno;

void mostrar_aluno(aluno a);
aluno preenche_aluno ();

int main()
{
    int qtd_alunos,i;
    aluno * turma;

    printf("\nDigite a quantidade de alunos: ");
    scanf("%d",&qtd_alunos);
    

    turma = (aluno*)calloc(qtd_alunos,sizeof(aluno));
    // turma = (aluno*)malloc(qtd_alunos * sizeof(aluno));

    for(i=0;i<qtd_alunos;i++)
    {
        turma[i] = preenche_aluno();
    } 

    for(i=0;i<qtd_alunos;i++)
    {
        mostrar_aluno(turma[i]);
    } 

    return 0;
}

aluno preenche_aluno ()
{
    int i;
    float som=0;

    aluno a;

    printf("\nDigite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a.nome,90,stdin);
    a.nome[strlen(a.nome)-1] = '\0';

    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&a.matricula);

    a.notas = (float*)calloc(3,sizeof(float));

    for(i=0;i<3;i++)
    {
        printf("\nDigite a %d nota: ",i+1);
        scanf("%f",&a.notas[i]);   
        som = som + a.notas[i];
    }

    a.media = som / 3.0;
    return a;
}

void mostrar_aluno(aluno a)
{
    printf("\nNome: %s Matricula: %d n1: %f n2: %f n3: %f Media: %f",a.nome,a.matricula,a.notas[0],a.notas[1],a.notas[2],a.media);
}

