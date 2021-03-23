// 2 ) Faça um programa que leia do usuário um número N positivo e construa uma lista ligada de alunos. Cada aluno possui
//     nome, matricula e media final. Disponibilize ao usuários as seguintes opções:

//     a) Inserir aluno na lista
//     b) Mostrar alunos aprovados
//     c) Mostrar alunos reprovados
//     d) Remover aluno da lista.

//     Obs. É considerado um aluno aprovado aquele que conter média final >=5.0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    char nome[30];
    long int matricula;
    float media;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, registro aluno);
void mostrar_alunos(lista *l, int aprovados);
void menu(lista *l);
int remover_aluno(lista *l, char * nome);
void mostrar_aluno(registro a);

int main()
{

    lista *l1;
    l1 = aloca_lista();

    menu(l1);

    printf("\n");
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    strcpy(novo->nome, "\0");
    novo->matricula = 0;
    novo->media = 0.0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, registro aluno)
{
    registro *novo, *aux;
    novo = aloca_registro();
    strcpy(novo->nome, aluno.nome);
    novo->matricula = aluno.matricula;
    novo->media = aluno.media;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    l->qtd++;
}

void mostrar_aluno(registro a)
{
    printf("\n Nome: %s\tMatricula: %ld\tMedia: %.2f", a.nome, a.matricula, a.media);
}

void mostrar_lista(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n lista vazia");
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            mostrar_aluno(*aux);
            aux = aux->prox;
        }
    }
}
void mostrar_alunos(lista *l, int aprovados)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n lista vazia");
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aprovados)
            {
                if (aux->media >= 5.0)
                {
                    mostrar_aluno(*aux);
                }
            }
            else
            {
                if (aux->media < 5.0)
                {
                    mostrar_aluno(*aux);
                }

            }
            aux = aux->prox;
        }
    }
}

void menu(lista *l)
{
    int opcao, numero;
    registro aluno;
    char nome_aluno[30];

    do
    {
        printf("\n 1 - Inserir aluno na lista");
        printf("\n 2 - Mostrar alunos aprovados");
        printf("\n 3 - Mostrar alunos reprovados");
        printf("\n 4 - Remover aluno");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite o nome do aluno: ");
            __fpurge(stdin);
            fgets(aluno.nome, 30, stdin);
            // aluno.nome[strlen(aluno.nome) - 1] = '\0';
            printf("\n Digite a matricula do aluno: ");
            scanf("%ld", &aluno.matricula);
            printf("\n Digite a media do aluno: ");
            scanf("%f", &aluno.media);
            incluir_no_final(l, aluno);
            break;
        case 2:
            mostrar_alunos(l,1);
            break;
        case 3:
            mostrar_alunos(l,0);
            break;
        case 4:
            printf("\n Digite o nome do aluno que deseja remover: ");
            __fpurge(stdin);
            fgets(nome_aluno,30,stdin);
            // nome_aluno[strlen(nome_aluno)-1] = '\0';
            if(remover_aluno(l,nome_aluno))
            {
                printf("\n Removido com sucesso");
            }
            else
            {
                printf("\n Aluno nao encontrado ou lista vazia");
            }
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);
}

int remover_aluno(lista *l, char * nome)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        
        if (strcmp(aux->nome,nome)==0)
        {
            
            if (ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1;
        }
        ant = aux;
        aux = aux->prox;
    }

    return 0;
}