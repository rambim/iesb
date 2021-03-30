/*
1) utilizando como base a solucao_lista2_exercicio3.c construa as seguintes funções para uma lista duplamente ligada:


    1 - Remover Primos
    2 - Remover numeros iguais
    3 - Buscar por numero
    4 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
    5 - incluir de forma ordenada

*/

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
void incluir_ordenado(lista *l, int x);
registro *aloca_registro();
void mostrar(lista * l);
int is_primo(int x);
int remover_todos_primos(lista *l);
int remover_todos_iguais(lista *l);
registro * buscar_por_numero(lista * l, int x);

int main(int argc, char *argv[])
{
    lista * l1;
    l1 = aloca_lista();

    incluir_ordenado(l1,2);
    incluir_ordenado(l1,8);
    incluir_ordenado(l1,3);
    incluir_ordenado(l1,7);
    incluir_ordenado(l1,8);
    incluir_ordenado(l1,10);
    incluir_ordenado(l1,7);
    incluir_ordenado(l1,9);
    incluir_ordenado(l1,5);
    incluir_ordenado(l1,1);
    incluir_ordenado(l1,10);
    remover_todos_iguais(l1);
    mostrar(l1);
    printf("\n");
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

void incluir_ordenado(lista *l, int x)
{
    registro *novo,*aux;
    novo = aloca_registro();
    novo->valor = x;
    

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->inicio;

        while(aux->prox!=NULL && aux->valor <x)
        {
            aux = aux->prox; 
        }

        if (aux->valor < x)
        {
            aux->prox = novo;
            novo->ant = aux;
            l->fim = novo;
        }
        else
        {
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant = novo;
            if (novo->ant == NULL)
            {
                l->inicio = novo;
            }
            else
            {
                novo->ant->prox = novo;
            }
            l->qtd++;
        }
    }
}

void mostrar(lista * l)
{
    if (l->inicio==NULL && l->fim == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro * aux;
    aux = l->inicio;
    while(aux!=NULL)
    {
        printf("\n%d",aux->valor);
        aux = aux->prox;
    }
}

int is_primo(int x)
{
    if (x==0 || x==1)
        return 0;
    
    int div;
    for(div=2;div<x;div++)
    {
        if (x%div==0)
        {
            return 0;
        }
    }
    return 1;
}

int remover_todos_primos(lista *l)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        if (is_primo(aux->valor))
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

            if (ant == NULL)
                aux = l->inicio;
            else
                aux = ant->prox;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    return 0;
}

int remover_todos_iguais(lista *l)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux->prox != NULL)
    {
        if (aux->valor == aux->prox->valor)
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

            if (ant == NULL)
                aux = l->inicio;
            else
                aux = ant->prox;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    return 0;
}

registro * buscar_por_numero(lista * l, int x)
{
    if (l->inicio==NULL && l->fim == NULL)
    {
        return NULL;
    }

    registro * aux;

    aux = l->inicio;
    while(aux!=NULL)
    {
        if (aux->valor == x)
        {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}

