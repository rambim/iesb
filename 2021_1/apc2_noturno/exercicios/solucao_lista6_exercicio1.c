#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

/*

Faça um programa que receba do usuário um número N, leia a informação de N alunos
e grave as informações dos N alunos em um arquivo alunos.json.

Informações do aluno:

nome
matricula
notas ( vetor de 3 notas)
media


Exemplo para 2 alunos:



*/

typedef struct aluno
{
    char nome[50];
    int matricula;
    float notas[3];
    float media;
} aluno;

float calcula_media(float *notas, int tam);
aluno preenche_aluno();
void mostra_aluno(aluno a);
int grava_json(aluno *turma, int tam, char *nome_do_arquivo);

int main()
{
    int n, i;
    aluno *turma;
    aluno x;

    printf("\nDigite o valor de N: ");
    scanf("%d", &n);

    turma = (aluno *)calloc(n, sizeof(aluno));

    for (i = 0; i < n; i++)
    {
        turma[i] = preenche_aluno();
    }

    for (i = 0; i < n; i++)
    {
        mostra_aluno(turma[i]);
    }

    grava_json(turma, n, "teste.json");

    free(turma);

    printf("\n");
    return 0;
}

aluno preenche_aluno()
{
    aluno a;
    int i;

    printf("\nDigite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a.nome, 48, stdin);
    a.nome[strlen(a.nome) - 1] = '\0';

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &a.matricula);

    for (i = 0; i < 3; i++)
    {
        printf("\nDigite a %d nota: ", i + 1);
        scanf("%f", &a.notas[i]);
    }

    a.media = calcula_media(a.notas, 3);
    return a;
}

void mostra_aluno(aluno a)
{
    printf("\nNome: %s\tMatricula: %d\tMedia: %f", a.nome, a.matricula, a.media);
}

float calcula_media(float *notas, int tam)
{
    float media, som = 0;
    int i;

    for (i = 0; i < tam; i++)
    {
        som = som + notas[i];
    }

    media = som / (float)tam;
    return media;
}

// 1 - arquivo gerado com sucesso
// 0 - arquivo não foi gerado.
int grava_json(aluno *turma, int tam, char *nome_do_arquivo)
{
    FILE *arq;
    int i, j;

    arq = fopen(nome_do_arquivo, "a");

    if (arq == NULL)
        return 0;
    fprintf(arq, "\n[");

    for (i = 0; i < tam; i++)
    {
        fprintf(arq, "\n\t{");
        fprintf(arq, "\n\t\t\"nome\": \"%s\",", turma[i].nome);
        fprintf(arq, "\n\t\t\"matricula\": %d,", turma[i].matricula);
        fprintf(arq, "\n\t\t\"notas\": [");

        for (j = 0; j < 3; j++)
        {

            fprintf(arq, "%.2f", turma[i].notas[j]);
            if (j != 2)
                fprintf(arq, ", ");
        }
        fprintf(arq, "],");

        fprintf(arq, "\n\t\t\"media\": %f", turma[i].media);
        fprintf(arq, "\n\t}");
        if (i < tam - 1)
        {
            fprintf(arq, ",");
        }
    }

    fprintf(arq, "\n]");
    fclose(arq);
}

// {
//     "nome": "Felippe",
//     "matricula": 123,
//     "notas": [ 9.5 , 8.5, 9.0],
//     "media" : 9.0
// },
// {
//     "nome": "Felippe2",
//     "matricula": 456,
//     "notas": [ 9.5 , 8.5, 9.0],
//     "media" : 9.0
// }