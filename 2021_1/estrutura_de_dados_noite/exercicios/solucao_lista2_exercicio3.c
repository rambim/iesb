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
void mostrar(lista *l, int inverso);
void incluir_no_inicio(lista *l, int x);
void incluir_no_final(lista *l, int x);
void menu(lista *l);

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
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_no_inicio(lista *l, int x)
{
    if (l == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

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
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_no_final(lista *l, int x)
{
    if (l == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

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

void mostrar(lista *l, int inverso)
{
    registro *aux;
    if (l->inicio == NULL || l->fim == NULL)
    {
        printf("\n lista vazia");
        return;
    }

    if (!inverso)
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
    else
    {
        aux = l->fim;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->ant;
        }
    }
}

void menu(lista *l)
{
    int opcao, numero;
    do
    {
        printf("\n1 - Incluir no inicio da lista");
        printf("\n2 - Incluir no final da lista");
        printf("\n3 - Mostrar lista");
        printf("\n4 - Mostrar lista inversa");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            incluir_no_inicio(l, numero);
            break;
        case 2:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            incluir_no_final(l, numero);
            break;
        case 3:
            mostrar(l, 0);
            break;
        case 4:
            mostrar(l, 1);
            break;
        case 5:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);
}