#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio_ext.h>

typedef struct aluno
{
    char nome[30];
    int matricula;
    float media;
} aluno;

void preenche_aluno(aluno *a,int x);
void mostra_aluno(aluno a);
void guarda_alunos(aluno * a, int qtd_alunos);
int main()
{
    aluno *a;
    int qtd_alunos = 10, i;
    a = (aluno *)calloc(qtd_alunos, sizeof(aluno));
    for (i = 0; i < qtd_alunos; i++)
    {
        preenche_aluno(&a[i],i);
    }

    for (i = 0; i < qtd_alunos; i++)
    {
        mostra_aluno(a[i]);
    }
    
    guarda_alunos(a,qtd_alunos);
    printf("\n");
    return 0;
}

void preenche_aluno(aluno *a,int x)
{

    char nome[30] = "Felippe";
    char str[10];
    sprintf(str, "%d", x);
    strcat(nome, " ");
    strcat(nome, str);
    strcpy(a->nome, nome);

    a->matricula = x;
    a->media = x;
}

void mostra_aluno(aluno a)
{
    printf("\n Nome: %s Matricula %d Media %f", a.nome, a.matricula, a.media);
}

void guarda_alunos(aluno * a, int qtd_alunos)
{
    FILE * arq;
    
    arq = fopen("alunos.txt","w");

    if (arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
        return ;
    }

    fwrite(a,sizeof(aluno),qtd_alunos,arq);
    fclose(arq);
}