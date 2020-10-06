#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void mostrar_do_fim(lista *l);
void mostrar_do_inicio(lista *l);

int main()
{
    lista *lista_teste;
    lista_teste = aloca_lista();
    incluir_no_final(lista_teste, 1);
    incluir_no_final(lista_teste, 2);
    incluir_no_final(lista_teste, 3);
    incluir_no_final(lista_teste, 4);
    incluir_no_final(lista_teste, 5);
    incluir_no_final(lista_teste, 6);

    printf("\n Mostrando indo: ");
    mostrar_do_inicio(lista_teste);

    printf("\n Mostrando vindo: ");
    mostrar_do_fim(lista_teste);

    printf("\n");
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }

    l->qtd++;
}

void mostrar_do_inicio(lista *l)
{
    registro *aux;
    if (l->inicio == NULL && l->fim == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n%d", aux->valor);
            aux = aux->prox;
        }
    }
}

void mostrar_do_fim(lista *l)
{
    registro *aux;
    if (l->inicio == NULL && l->fim == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        aux = l->fim;
        while (aux != NULL)
        {
            printf("\n%d", aux->valor);
            aux = aux->ant;
        }
    }
}
