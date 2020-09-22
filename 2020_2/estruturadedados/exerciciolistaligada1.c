#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

registro *aloca_registro();
lista *aloca_lista();
void incluir_na_lista(lista *l, int x);
void mostrar(lista *l);
void remove_na_lista(lista *l, int x);
void remove_todos_na_lista(lista *l, int x);

int main()
{
    lista *lista_de_pares, *lista_de_impares;
    int numero = 0;

    int i;

    lista_de_pares = aloca_lista();
    lista_de_impares = aloca_lista();

    for (i = 0; i < 10; i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d", &numero);

        if (numero % 2 == 0)
        {
            incluir_na_lista(lista_de_pares, numero);
        }
        else
        {
            incluir_na_lista(lista_de_impares, numero);
        }
    }

    if (lista_de_pares->qtd>lista_de_impares->qtd)
    {
        mostrar(lista_de_pares);
    }
    else
    {
        mostrar(lista_de_impares);
    }

    return 0;    
}

lista *aloca_lista()
{
    lista *nova_lista;

    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;
    return nova_lista;
}

registro *aloca_registro()
{
    registro *novo_registro;
    novo_registro = (registro *)malloc(sizeof(registro));
    novo_registro->valor = 0;
    novo_registro->prox = NULL;
    return novo_registro;
}

void incluir_na_lista(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

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

void mostrar(lista *l)
{
    registro *aux;

    if (l->qtd == 0)
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

void remove_na_lista(lista *l, int x)
{

    registro *welisson, *morcego;

    if (l->inicio == NULL)
    {
        printf("\n lista vazia");
        return;
    }
    welisson = l->inicio;

    while (welisson != NULL)
    {
        if (welisson->valor == x)
        {
            if (morcego == NULL)
            {
                l->inicio = welisson->prox;
            }
            else
            {
                morcego->prox = welisson->prox;
            }

            free(welisson);
            l->qtd--;
            printf("\n Removido com sucesso");
            return;
        }
        else
        {
            morcego = welisson;
            welisson = welisson->prox;
        }
    }
    printf("\n Elemento nao foi encontrado na lista");

    return;
}

void remove_todos_na_lista(lista *l, int x)
{

    registro *welisson, *morcego;
    int apagou = 0;

    if (l->inicio == NULL)
    {
        printf("\n lista vazia");
        return;
    }
    welisson = l->inicio;

    while (welisson != NULL)
    {
        if (welisson->valor == x)
        {
            if (morcego == NULL)
            {
                l->inicio = welisson->prox;
            }
            else
            {
                morcego->prox = welisson->prox;
            }

            free(welisson);
            l->qtd--;
            printf("\n Removido com sucesso");
            apagou = 1;
            welisson = morcego->prox;
        }
        else
        {
            morcego = welisson;
            welisson = welisson->prox;
        }
    }
    if (!apagou)
    {
        printf("\n Elemento nao foi encontrado na lista");
    }

    return;
}