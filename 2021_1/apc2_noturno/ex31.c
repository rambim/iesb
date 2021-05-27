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

aluno *aloca_alunos(int qtd_alunos);
void mostrar_turma(aluno *turma, int qtd_alunos);
void preenche_aluno(aluno *a);
int incluir_aluno(aluno *turma, int tam, int *qtd_alunos);
void menu(aluno *turma, int *tamanho_da_turma, int *qtd_alunos);
int recupera_qtd_alunos();
int atualiza_qtd_alunos(int qtd_alunos);
int recupera_qtd_alunos();
int atualiza_qtd_alunos(int qtd_alunos);
aluno *recupera_lista_alunos(int qtd_alunos, int tamanho_turma);
int atualiza_lista_alunos(aluno *turma, int qtd_alunos);

int main()
{
    aluno *turma;
    int qtd_alunos;
    int tamanho_da_turma = 10;
    int retorno;

    FILE *arq;

    qtd_alunos = recupera_qtd_alunos();

    turma = recupera_lista_alunos(qtd_alunos,tamanho_da_turma);

    if (turma == NULL)
    {
        turma = aloca_alunos(tamanho_da_turma);
    }

    menu(turma, &tamanho_da_turma, &qtd_alunos);
    atualiza_lista_alunos(turma,qtd_alunos);
    

    printf("\n");
    return 0;
}

aluno *aloca_alunos(int qtd_alunos)
{
    aluno *vet;
    vet = (aluno *)calloc(qtd_alunos, sizeof(aluno));
    return vet;
}

int incluir_aluno(aluno *turma, int tam, int *qtd_alunos)
{
    if (*qtd_alunos >= tam)
    {
        printf("\nTurma Cheia");
        return 0;
    }

    preenche_aluno(&turma[*qtd_alunos]);
    (*qtd_alunos)++;
    return 1;
}

void preenche_aluno(aluno *a)
{
    printf("\nDigite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a->nome, 28, stdin);
    a->nome[strlen(a->nome) - 1] = '\0';
    printf("\nDigite a matricula do aluno: ");
    __fpurge(stdin);
    scanf("%d", &a->matricula);
    printf("\nDigite a media do aluno: ");
    __fpurge(stdin);
    scanf("%f", &a->media);
}

void mostrar_turma(aluno *turma, int qtd_alunos)
{
    int i;
    printf("\nTurma: ");
    for (i = 0; i < qtd_alunos; i++)
        printf("\nNome: %s\tMatricula: %d\tMedia: %f", turma[i].nome, turma[i].matricula, turma[i].media);
}

void menu(aluno *turma, int *tamanho_da_turma, int *qtd_alunos)
{
    int opcao, retorno;

    do
    {
        printf("\n01 - Incluir aluno");
        printf("\n02 - Mostrar alunos");
        printf("\n10 - Sair do programa");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            retorno = incluir_aluno(turma, *tamanho_da_turma, qtd_alunos);

            if (retorno == 1)
                printf("\nAluno incluido com sucesso");
            else
                printf("\nAluno nao foi incluido.");
            break;
        case 2:
            if (*qtd_alunos == 0)
                printf("\nTurma Vazia");
            else
                mostrar_turma(turma, *qtd_alunos);
            break;
        case 10:
            printf("\nSaindo do programa");
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }
    } while (opcao != 10);
}

int recupera_qtd_alunos()
{
    FILE *arq;

    int qtd_alunos;
    arq = fopen("qtd_alunos.txt", "r");

    if (arq == NULL)
        return 0;

    fscanf(arq, "%d", &qtd_alunos);
    fclose(arq);
    return qtd_alunos;
}

int atualiza_qtd_alunos(int qtd_alunos)
{
    FILE *arq;

    arq = fopen("qtd_alunos.txt", "w");

    if (arq == NULL)
        return 0;

    printf("\nAtualizando quantidade para %d",qtd_alunos);
    fprintf(arq,"%d", qtd_alunos);
    fclose(arq);
    return 1;
}

aluno *recupera_lista_alunos(int qtd_alunos, int tamanho_turma)
{
    FILE *arq;

    aluno *nova_turma;

    arq = fopen("lista_alunos.txt", "r");

    if (arq == NULL)
    {
        printf("\nNão foi  possivel recuperar a lista de alunos");
        return NULL;
    }

    nova_turma = (aluno *)malloc(sizeof(aluno) * tamanho_turma);
    fread(nova_turma, qtd_alunos, sizeof(aluno), arq);
    fclose(arq);

    return nova_turma;
}

int atualiza_lista_alunos(aluno *turma, int qtd_alunos)
{
    FILE *arq;
    int retorno;

    arq = fopen("lista_alunos.txt", "w");

    if (arq == NULL)
    {
        printf("\nErro na atualizacao da lista de alunos");
        return 0;
    }

    fwrite(turma, qtd_alunos, sizeof(aluno), arq);
    fclose(arq);
    retorno = atualiza_qtd_alunos(qtd_alunos);

    if (retorno == 1)
        printf("\n Quantidade de alunos e lista atualizada com sucesso");
    else
        printf("\nErro na atualizacao da quantidade de alunos");

    return 1;
}
