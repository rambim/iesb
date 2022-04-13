#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct registro
{

    char palavra[50];
    struct registro *prox;
} registro;
typedef struct lista
{
    int qtd;
    struct registro *inicio;

} lista;

void mostrar_lista(lista *l);
lista *aloca_lista();
registro *aloca_registro();
void incluir_registro_inicio(lista *l, char * palavra);
void incluir_registro_final(lista *l, char * palavra);
int buscar(lista *l, char * palavra);
void menu(lista *l);
int remover(lista *l, char * palavra);

int main()
{
    lista *l1, *l2;

    l1 = aloca_lista();
    l2 = aloca_lista();

    menu(l1);

    return 0;
}

void menu(lista *l)
{
    int opcao;
    char palavra[50];

    do
    {
        printf("\n 01 - Incluir no inicio");
        printf("\n 02 - Incluir no final");
        printf("\n 03 - Mostrar lista");
        printf("\n 04 - Buscar palavra");
        printf("\n 05 - Remover palavra");
        printf("\n 10 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite uma palavra:");
            //windows fflush(stdin);
            __fpurge(stdin);
            fgets(palavra,50,stdin);
            palavra[strlen(palavra)-1] = '\0';
            incluir_registro_inicio(l, palavra);
            break;
        case 2:
            printf("\n Digite um palavra:");
            __fpurge(stdin);
            fgets(palavra,50,stdin);
            palavra[strlen(palavra)-1] = '\0';
            incluir_registro_final(l, palavra);
            break;
        case 3:
            mostrar_lista(l);
            break;
        case 4:
            printf("\n Digite um palavra:");
            __fpurge(stdin);
            fgets(palavra,50,stdin);
            palavra[strlen(palavra)-1] = '\0';

            if (buscar(l, palavra))
            {
                printf("\n palavra encontrada");
            }
            else
            {
                printf("\n palavra nao esta na lista");
            }
            break;
        case 5:
            printf("\n Digite um palavra:");
            __fpurge(stdin);
            fgets(palavra,50,stdin);
            palavra[strlen(palavra)-1] = '\0';
            if (remover(l,palavra))
            {
                printf("\n palavra removida ");
            }
            else
            {
                printf("\n palavra nao removido ou lista vazia");
            }
            break;
        case 10:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 10);
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->qtd = 0;
    return novo;
}

registro *aloca_registro()
{

    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    strcpy(novo->palavra,"\0");
    novo->prox = NULL;
    return novo;
}

void incluir_registro_inicio(lista *l, char * palavra)
{
    registro *novo;
    novo = aloca_registro();

    strcpy(novo->palavra, palavra);

    if (l->inicio == NULL)
    {

        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_registro_final(lista *l, char * palavra)
{
    registro *novo, *aux;
    novo = aloca_registro();
    strcpy(novo->palavra,palavra);

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

void mostrar_lista(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf(" %s", aux->palavra);
            aux = aux->prox;
        }
    }
}

int buscar(lista *l, char * palavra)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        registro *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            if (strcmp(aux->palavra,palavra)==0)
            {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

int remover(lista *l, char * palavra)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        registro *aux = NULL, *ant = NULL;
        aux = l->inicio;

        while (aux != NULL)
        {
            if (strcmp(aux->palavra,palavra)==0)
            {
                if (ant == NULL)
                {
                    l->inicio = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                free(aux);
                l->qtd--;
                return 1;
            }
            ant = aux;
            aux = aux->prox;
        }
    }
}