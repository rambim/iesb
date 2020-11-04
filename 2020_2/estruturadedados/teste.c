#include <stdio.h>
#include <stdlib.h>

//structs
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

lista *concatena(lista *l1, lista *l2);
lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void mostrar(lista *l);

//principal
int main()
{
    int x = 0, num;
    lista *lista_1 = aloca_lista(), *lista_2 = aloca_lista(), *lista_concatenada = aloca_lista();

    for (x = 0; x < 10; x++)
    {
        printf("\nDigite um numero inteiro positivo:");
        scanf("%d", &num);
        if (x < 5)
        {
            incluir_no_final(lista_1, num);
        }
        else if (x >= 5)
        {
            incluir_no_final(lista_2, num);
        }
    }
    lista_concatenada = concatena(lista_1, lista_2);
    mostrar(lista_concatenada);
}
//funçoes
lista *aloca_lista()
{
    lista *nova_lista;

    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    ;
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

void incluir_no_final(lista *l, int x)
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

    if (l->inicio == NULL)
    {
        printf("Lista vazia\n");
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

lista *concatena(lista *l1, lista *l2)
{
    registro *aux;
    lista *lista_concat = aloca_lista();
    aux = l1->inicio;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = l2->inicio;
    lista_concat->inicio = l1->inicio;
    return lista_concat;
}