#include <stdio.h>
#include <stdlib.h>

typedef struct lista_duplamente_ligada
{
    struct registro *inicio;
    struct registro *fim;
} lista_duplamente_ligada;

typedef struct registro
{
    int valor;
    struct registro *ant;
    struct registro *prox;
} registro;

lista_duplamente_ligada *concatena_listas(lista_duplamente_ligada *a, lista_duplamente_ligada *b);
void incluir(lista_duplamente_ligada *l, int x, int tipo_inclusao);
void mostrar(lista_duplamente_ligada *l, int tipo_mostrar);
int remover(lista_duplamente_ligada *l, int x);

lista_duplamente_ligada *aloca_lista_dupla()
{
    lista_duplamente_ligada *novo;
    novo = (lista_duplamente_ligada *)calloc(1, sizeof(lista_duplamente_ligada));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

// tipo_inclusao 1 : incluir no inicio da lista
// tipo_inclusao 2 : incluir no fim da lista
void incluir(lista_duplamente_ligada *l, int x, int tipo_inclusao)
{
    if (l == NULL)
        return;

    if (tipo_inclusao != 1 && tipo_inclusao != 2)
    {
        printf("\n Tipo de inclusao informado incorreto");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        switch (tipo_inclusao)
        {
        case 1:
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
            break;
        case 2:
            l->fim->prox = novo;
            novo->ant = l->fim;
            l->fim = novo;
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }
}

void mostrar(lista_duplamente_ligada *l, int tipo_mostrar)
{
    if (l == NULL)
    {
        printf("\n Lista nao alocada");
        return;
    }

    if (tipo_mostrar != 1 && tipo_mostrar != 2)
    {
        printf("\n Tipo mostrar invalido");
        return;
    }

    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux;

    switch (tipo_mostrar)
    {
    case 1:
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->prox;
        }
        break;
    case 2:
        aux = l->fim;
        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->ant;
        }
        break;
    default:
        printf("\n opcao invalida");
        break;
    }
}

// 1 - removeu
// 0 - não removeu
int remover(lista_duplamente_ligada *l, int x)
{
    if (l == NULL)
        return 0;
    if (l->inicio == NULL)
        return 0;

    registro *aux;

    aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (aux->ant == NULL)
                l->inicio = aux->prox;
            else
                aux->ant->prox = aux->prox;

            if (aux->prox == NULL)
                l->fim = aux->ant;
            else
                aux->prox->ant = aux->ant;
            return 1;
        }
        else
        {
            aux = aux->prox;
        }
    }
    return 0;
}

int main()
{

    lista_duplamente_ligada *l1=NULL, *l2=NULL, *l3=NULL;

    int i = 5, numero;

    l1 = aloca_lista_dupla();

    printf("\n Digite 5 numeros: ");
    while (i--)
    {
        scanf("%d", &numero);
        incluir(l1, numero, 2);
    }

    l2 = aloca_lista_dupla();

    i = 5;
    printf("\n Digite 5 numeros: ");
    while (i--)
    {
        scanf("%d", &numero);
        incluir(l2, numero, 2);
    }

    printf("\n Mostrando primeira lista: ");
    mostrar(l1, 1);
    printf("\n Mostrando segunda lista: ");
    mostrar(l2, 1);

    l3 = concatena_listas(l1,l2);

    printf("\n Mostrando terceira lista:");
    mostrar(l3,1);
    printf("\n");
    return 0;
}

lista_duplamente_ligada *concatena_listas(lista_duplamente_ligada *a, lista_duplamente_ligada *b)
{
    lista_duplamente_ligada *c;

    registro *aux;
    c = aloca_lista_dupla();

    if (a != NULL)
    {
        aux = a->inicio;
        while (aux != NULL)
        {
            incluir(c, aux->valor, 2);
            aux=aux->prox;
        }
    }

    if (b != NULL)
    {
        aux = b->inicio;
        while (aux != NULL)
        {
            incluir(c, aux->valor, 2);
            aux=aux->prox;
        }
    }

    return c;
}
