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

void mostra_aluno(aluno a);

int main()
{
    FILE * arq;
    aluno * a;
    int i;

    a = (aluno*)calloc(10,sizeof(aluno));

    arq = fopen("alunos.txt","r");

    if ( arq==NULL)
    {
        printf("\n Problemas na leitura do arquivo");
    }
    else
    {
        fread(a,sizeof(aluno),10,arq);
        // fread(&a[2],sizeof(aluno),2,arq);
        fclose(arq);
    }

    for(i=0;i<10;i++)
    {
        mostra_aluno(a[i]);
    }

}

void mostra_aluno(aluno a)
{
    printf("\n Nome: %s Matricula %d Media %f", a.nome, a.matricula, a.media);
}