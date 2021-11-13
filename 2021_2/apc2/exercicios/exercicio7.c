#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct aluno
{
    int matricula;
    char nome[50];
    int qtd_notas;
    float *notas;
    float media;
} aluno;

aluno recebe_aluno();
void mostrar_aluno(aluno a);
float calcula_media(float *notas, int qtd_notas);
int indice_maior_media(aluno *turma, int qtd_alunos);
int main()
{
    aluno *turma;

    int qtd_alunos, i;

    FILE *arq;

    printf("\n Digite N(qtd de alunos) : ");
    scanf("%d", &qtd_alunos);

    // turma = (aluno*)calloc(qtd_alunos,sizeof(aluno));
    turma = (aluno *)malloc(sizeof(aluno) * qtd_alunos);

    for (i = 0; i < qtd_alunos; i++)
    {
        turma[i] = recebe_aluno();
    }

    for (i = 0; i < qtd_alunos; i++)
    {
        mostrar_aluno(turma[i]);
    }

    arq = fopen("melhor_aluno.txt", "w");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        int indice_melhor_aluno = indice_maior_media(turma,qtd_alunos);
        
        fprintf(arq,"\n Nome: %s", turma[indice_melhor_aluno].nome);
        fprintf(arq,"\n Matricula: %d", turma[indice_melhor_aluno].matricula);
        fprintf(arq,"\n Qtd notas: %d", turma[indice_melhor_aluno].qtd_notas);

        for (i = 0; i < turma[indice_melhor_aluno].qtd_notas; i++)
        {
            fprintf(arq,"\n Nota %d = %f", i + 1, turma[indice_melhor_aluno].notas[i]);
        }
        fprintf(arq,"\n Media: %f", turma[indice_melhor_aluno].media);
        printf("\n");
    }

    printf("\n");
    return 0;
}

aluno recebe_aluno()
{
    aluno a;
    int i;
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &a.matricula);
    printf("\n Digite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a.nome, 100, stdin);
    a.nome[strlen(a.nome) - 1] = '\0';
    printf("\n Digite a quantidade de notas: ");
    scanf("%d", &a.qtd_notas);

    a.notas = (float *)malloc(sizeof(float) * a.qtd_notas);

    for (i = 0; i < a.qtd_notas; i++)
    {
        printf("\n Digite a %d nota: ", i + 1);
        scanf("%f", &a.notas[i]);
    }

    a.media = calcula_media(a.notas, a.qtd_notas);

    return a;
}

void mostrar_aluno(aluno a)
{
    int i;
    printf("\n Nome: %s", a.nome);
    printf("\n Matricula: %d", a.matricula);
    printf("\n Qtd notas: %d", a.qtd_notas);

    for (i = 0; i < a.qtd_notas; i++)
    {
        printf("\n Nota %d = %f", i + 1, a.notas[i]);
    }
    printf("\n Media: %f", a.media);
    printf("\n");
}

float calcula_media(float *notas, int qtd_notas)
{
    float sum = 0;
    int i;

    for (i = 0; i < qtd_notas; i++)
    {
        sum = sum + notas[i];
    }

    return sum / (float)qtd_notas;
}

int indice_maior_media(aluno *turma, int qtd_alunos)
{
    int i;
    float maior_media = 0;
    int indice_maior_media = 0;
    for (i = 0; i < qtd_alunos; i++)
    {
        if (turma[i].media > maior_media)
        {
            maior_media = turma[i].media;
            indice_maior_media = i;
        }
    }

    return indice_maior_media;
}