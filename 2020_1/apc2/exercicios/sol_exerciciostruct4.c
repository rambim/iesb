#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct aluno
{
    int matricula;
    float media;
} aluno;

void preenche_aluno1(aluno *a);
aluno preenche_aluno2();
void preenche_turma(aluno *turma, int qtd);
void mostra_vetor(aluno *vet, int qtd);

int main()
{
    aluno turma[tam];
    int i;
    aluno aprovados[tam], reprovados[tam];
    int qtd_aprovados = 0, qtd_reprovados = 0;

    preenche_turma(turma, tam);

    for (i = 0; i < tam; i++)
    {
        if (turma[i].media < 5)
        {
            reprovados[qtd_reprovados] = turma[i];
            qtd_reprovados++;
        }
        else
        {
            aprovados[qtd_aprovados] = turma[i];
            qtd_aprovados++;
        }
    }

    printf("\n Turma inteira: ");
    mostra_vetor(turma,tam);

    printf("\n Aprovados: ");
    mostra_vetor(aprovados,qtd_aprovados);

    printf("\n Reprovados: ");
    mostra_vetor(reprovados,qtd_reprovados);

    return 0;
}

void preenche_aluno1(aluno *a)
{
    printf("\n Digite a matricula do aluno: ");
    scanf("%d", &a->matricula);
    printf("\n Digite a media: ");
    scanf("%f", &a->media);
}

aluno preenche_aluno2()
{
    aluno a;
    printf("\n Digite a matricula do aluno: ");
    scanf("%d", &a.matricula);
    printf("\n Digite a media: ");
    scanf("%f", &a.media);

    return a;
}

void preenche_turma(aluno *turma, int qtd)
{
    int i;
    int meio;
    meio = qtd / 2;
    for (i = 0; i < meio; i++)
    {
        preenche_aluno1(&turma[i]);
    }

    for (i = meio; i < qtd; i++)
    {
        turma[i] = preenche_aluno2();
    }
}

void mostra_vetor(aluno *vet, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++)
    {
        printf("\n Matricula: %d",vet[i].matricula );
        printf("\n Media    : %f",vet[i].media);
    }
}