#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct aluno
{
    int matricula;
    char nome[50];
    int m;
    float * notas;
    float media;
}aluno;

float calcula_media(float * notas, int qtd);
aluno preenche_aluno();
void mostrar_aluno( aluno a);
void grava_arquivo_aluno( aluno a);

int main()
{
    int n;
    aluno * turma;
    int i;
    int indice_aluno_maior_media=0;

    printf("\nDigite a quantidade de alunos: ");
    scanf("%d",&n);

    turma = (aluno*)calloc(n,sizeof(aluno));

    for(i=0;i<n;i++)
    {
        turma[i] = preenche_aluno();

        if (turma[i].media > turma[indice_aluno_maior_media].media)
        {
            indice_aluno_maior_media = i;
        }
    }

    grava_arquivo_aluno(turma[indice_aluno_maior_media]);

    printf("\n");
    return 0;
}

aluno preenche_aluno()
{
    aluno a;
    int i;
    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&a.matricula);

    printf("\nDigite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a.nome,48,stdin);
    a.nome[strlen(a.nome)-1] = '\0';

    printf("\nDigite a quantidade de notas do aluno: ");
    scanf("%d",&a.m);

    a.notas = (float*)calloc(a.m,sizeof(float));

    for(i=0;i<a.m;i++)
    {
        printf("\nDigite a %d nota: ",i+1);
        scanf("%f",&a.notas[i]);
    }

    a.media = calcula_media(a.notas,a.m);

    return a;

}

float calcula_media(float * notas, int qtd)
{
    int i;
    float som=0,media;

    for(i=0;i<qtd;i++)
    {
        som = som + notas[i];
    }

    media = som/(float)qtd;
    return media;
}

void mostrar_aluno( aluno a)
{
    printf("\nNome: %s Matricula: %d Media: %f",a.nome,a.matricula,a.media);
}

void grava_arquivo_aluno( aluno a)
{
    FILE * arq;
    int i;

    arq = fopen("melhor_aluno.txt","w");

    if ( arq==NULL)
    {
        printf("\nProblemas na abertura do arquivo");
    }
    else
    {
        fprintf(arq,"\nNome: %s Matricula: %d Media: %f\n",a.nome,a.matricula,a.media);
        for(i=0;i<a.m;i++)
        {
            fprintf(arq,"Nota %d : %f",i+1,a.notas[i]);
        }
        fclose(arq);
    }
}