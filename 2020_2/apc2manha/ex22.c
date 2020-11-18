/*
Na sua função principal, utilizando a função de calculo de médias criada, leia os dados de todos os alunos, suas respectivas M notas e diga qual a média de cada um dos alunos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct aluno
{
    char nome[50];
    long int matricula;
    float *notas;
    int m;

} aluno;

void preenche_aluno(aluno *a);
float media(float *vet, int qtd);

int main()
{
    int n;
    aluno *turma;
    int i;

    printf("\nDigite o valor de N: ");
    scanf("%d", &n);

    turma = (aluno *)malloc(sizeof(aluno) * n);

    for (i = 0; i < n; i++)
    {
        preenche_aluno(&turma[i]);
    }

    FILE *arq;

    arq = fopen("notas.txt", "w");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {

        for (i = 0; i < n; i++)
        {
            fprintf(arq,"Nome: %s Matricula: %ld Media %f\n", turma[i].nome, turma[i].matricula, media(turma[i].notas, turma[i].m));
        }
    }

    return 0;
}

void preenche_aluno(aluno *a)
{
    printf("\nDigite seu nome: ");
    __fpurge(stdin);
    //fflush(stdin);
    fgets(a->nome, 50, stdin);
    a->nome[strlen(a->nome) - 1] = '\0';

    printf("\nDigite sua matricula: ");
    scanf("%ld", &a->matricula);

    printf("\nDigite a quantidade de notas: ");
    scanf("%d", &a->m);

    a->notas = (float *)malloc(sizeof(float) * a->m);

    int i;

    for (i = 0; i < a->m; i++)
    {
        printf("\n Digite a %d nota: ", i + 1);
        scanf("%f", &a->notas[i]);
    }
}

float media(float *vet, int qtd)
{
    float som = 0;
    int i;
    for (i = 0; i < qtd; i++)
    {
        som = som + vet[i];
    }

    return som / qtd;
}