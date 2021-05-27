#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct aluno
{
    char nome[30];
    int matricula;
    float media;
} aluno;

int main()
{
    FILE *arq;

    // int x = 10;

    // arq = fopen("configuracoes.txt","w");

    // if ( arq==NULL)
    // {
    //     printf("\nProblemas na abertura do arquivo");
    // }
    // else
    // {
    //     fprintf(arq,"O valor de x = %d\n",x);
    //     fclose(arq);
    // }

    // int x;
    // aluno a[4];
    // int i;
    // arq = fopen("configuracoes.txt", "r");

    // if (arq == NULL)
    // {
    //     printf("\nProblemas na abertura do arquivo");
    // }
    // else
    // {
    //     for (i = 0; i < 4; i++)
    //     {
    //         fscanf(arq, "Nome: %s\tMatricula: %d\tMedia: %f\n", a[i].nome, &a[i].matricula, &a[i].media);
    //     }
    //     fclose(arq);
    // }

    // for (i = 0; i < 4; i++)
    // {
    //     printf("Nome: %s\tMatricula: %d\tMedia: %f\n", a[i].nome, a[i].matricula, a[i].media);
    // }

    // int x;
    // char linha[999];
    // arq = fopen("configuracoes.txt", "r");

    // if (arq == NULL)
    // {
    //     printf("\nProblemas na abertura do arquivo");
    // }
    // else
    // {
    //     while (fgets(linha, 997, arq) != NULL)
    //     {
    //         printf("Conteudo da linha: %s", linha);
    //     }
    //     fclose(arq);
    // }

    // int x = 13;

    // arq = fopen("configuracoes.txt","a");

    // if ( arq==NULL)
    // {
    //     printf("\nProblemas na abertura do arquivo");
    // }
    // else
    // {
    //     fprintf(arq,"O valor de x = %d\n",x);
    //     fclose(arq);
    // }
    // printf("\n");

    // aluno a;
    // strcpy(a.nome,"Felippe");
    // a.media = 10;
    // a.matricula = 123;

    // arq = fopen("configuracoes.txt","a");

    // if ( arq==NULL)
    // {
    //     printf("\nProblemas na abertura do arquivo");
    // }
    // else
    // {
    //     fprintf(arq,"Nome: %s\tMatricula: %d\tMedia: %f\n", a.nome, a.matricula, a.media);
    //     fclose(arq);
    // }

    // aluno a;
    // strcpy(a.nome,"Felippe");
    // a.media = 10;
    // a.matricula = 123;

    // arq = fopen("configuracoes.txt","w");

    // if ( arq==NULL)
    // {
    //     printf("\nProblemas na abertura do arquivo");
    // }
    // else
    // {
    //     fwrite(&a,1,sizeof(aluno),arq);
    //     fclose(arq);
    // }

    aluno a[3];

    // strcpy(a[0].nome,"Felippe1");
    // a[0].media = 10;
    // a[0].matricula = 123;

    // strcpy(a[1].nome,"Felippe2");
    // a[1].media = 11;
    // a[1].matricula = 456;

    // strcpy(a[2].nome,"Felippe3");
    // a[2].media = 12;
    // a[2].matricula = 789;

    arq = fopen("configuracoes.txt", "r");

    if (arq == NULL)
    {
        printf("\nProblemas na abertura do arquivo");
    }
    else
    {
        fread(a, 3, sizeof(aluno), arq);
        fclose(arq);
    }

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Nome: %s\tMatricula: %d\tMedia: %f\n", a[i].nome, a[i].matricula, a[i].media);
    }

    printf("\n");

    return 0;
}