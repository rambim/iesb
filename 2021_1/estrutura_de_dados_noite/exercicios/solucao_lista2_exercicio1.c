// 1 ) Faça um programa que receba do usuário um número N e preencha 2 listas ligadas com N números aleatórios.
//     Depois de preenchida as 2 listas, remova os números em comum das 2 listas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void mostrar_lista(lista *l);
void incluir_ordenado(lista *l, int x);
int remover_todos_primos(lista *l, int x);
lista *numeros_comuns(lista *l1, lista *l2);

int main()
{

    srand(time(NULL));
    lista *l1, *l2, *lista_comum;
    int n, i, numero_aleatorio;

    registro * aux;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("\n Digite um valor N: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        numero_aleatorio = rand() % 20;
        printf("\n Incluindo numero %d na lista 1",numero_aleatorio);
        incluir_ordenado(l1,numero_aleatorio);

        numero_aleatorio = rand() % 20;
        printf("\n Incluindo numero %d na lista 2",numero_aleatorio);
        incluir_ordenado(l2,numero_aleatorio);
    }

    printf("\n Mostrando lista 1: ");
    mostrar_lista(l1);
    printf("\n Mostrando lista 2: ");
    mostrar_lista(l2);

    lista_comum = numeros_comuns(l1, l2);

    printf("\n Numeros em comum: ");
    mostrar_lista(lista_comum);

    if (lista_comum!=NULL)
    {
        aux = lista_comum->inicio;
        while(aux!=NULL)
        {
            remover_todos_primos(l1,aux->valor);
            remover_todos_primos(l2,aux->valor);
            aux=aux->prox;
        }
    }

    printf("\n Depois de removido os numeros em comum: ");
    printf("\n Mostrando lista 1: ");
    mostrar_lista(l1);
    printf("\n Mostrando lista 2: ");
    mostrar_lista(l2);

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
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}


void incluir_ordenado(lista *l, int x)
{
    registro *aux = NULL, *ant = NULL;
    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL && aux->valor <= x)
        {
            ant = aux;
            aux = aux->prox;
        }

        if (aux->valor >= x)
        {
            if (ant == NULL)
                l->inicio = novo;
            else
                ant->prox = novo;

            novo->prox = aux;
        }
        else
        {
            aux->prox = novo;
        }
    }
    l->qtd++;
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
            printf("\n Valor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}


int remover_todos_primos(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->valor == x)
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

lista *numeros_comuns(lista *l1, lista *l2)
{
    lista *l;
    l = aloca_lista();
    registro *aux1 = NULL;
    registro *aux2 = NULL;
    aux1 = l1->inicio;
    aux2 = l2->inicio;
    while (aux1 != NULL && aux2 != NULL)
    {
        
        if (aux1->prox != NULL)
        {
            if (aux1->prox->valor < aux1->valor)
            {
                printf("\n A lista l1 não esta ordenada");
                return NULL;
            }
        }
        if (aux2->prox != NULL)
        {
            if (aux2->prox->valor < aux2->valor)
            {
                printf("\n A lista l2 não esta ordenada");
                return NULL;
            }
        }

        if (aux1->valor == aux2->valor)
        {
            incluir_ordenado(l, aux1->valor);
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        else
        {
            if (aux1->valor < aux2->valor)
                aux1 = aux1->prox;
            else
                aux2 = aux2->prox;
        }
    }
    return l;
}

