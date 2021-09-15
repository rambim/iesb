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
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void push(lista *p, int x);
int empty(lista *p);
int pop(lista *p);

int main()
{
    lista *p1;
    p1 = aloca_lista();
    push(p1, 1);
    push(p1, 2);
    push(p1, 3);
    push(p1, 4);
    push(p1, 5);

    printf("\n");

    int i = 5;
    while(i--)
    {
        printf("\n Removido da pilha : %d",pop(p1));
    }

    free(p1);
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void push(lista *p, int x)
{
    if (p == NULL)
    {
        printf("\n Pilha nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (p->inicio == NULL)
    {
        p->inicio = novo;
    }
    else
    {
        novo->prox = p->inicio;
        p->inicio = novo;
    }
    p->qtd++;
}

int empty(lista *p)
{

    if (p == NULL)
        return 1;
    if (p->inicio == NULL)
        return 1;
    else
        return 0;
}

int pop(lista *p)
{
    if (!empty(p))
    {
        registro *aux;
        int retorno;
        aux = p->inicio;
        p->inicio = aux->prox;
        retorno = aux->valor;
        free(aux);
        p->qtd--;
        return retorno;
    }
    else
    {
        return 0;
    }
}
