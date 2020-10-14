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
void incluir_ordenado(lista *l, int x);
void mostrar(lista *l);
void remove_na_lista(lista *l, int x);
void remove_todos_na_lista(lista *l, int x);

int main()
{
    lista *lista_do_felippe;
    int numero = 0;

    lista_do_felippe = aloca_lista();

    int opcao;

    do
    {
        mostrar(lista_do_felippe);
        printf("\n Digite um numero para ser includo na lista: ");
        scanf("%d", &numero);
        
        incluir_ordenado(lista_do_felippe, numero);
    } while (numero !=-1);
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

void incluir_ordenado(lista *l, int x)
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

        if (aux->valor > novo->valor)
        {
            novo->prox = l->inicio;
            l->inicio = novo;
        }
        else
        {
            while (aux->prox != NULL)
            {
                if (aux->prox->valor < novo->valor)
                {
                    aux = aux->prox;
                }
                else
                {
                    break;
                }
            }

            novo->prox = aux->prox;
            aux->prox = novo;
        }
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