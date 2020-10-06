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
    struct registro *ant;
    struct registro *prox;
} registro;

registro *aloca_registro();
lista *aloca_lista();
void mostrar(lista *l);
void incluir_no_final(lista *l, int x);
void incluir_no_inicio(lista *l, int x);

int main()
{
    int opcao;
    int numero;

    lista *l;
    l = aloca_lista();

    do
    {
        printf("\n1 - Incluir no inicio");
        printf("\n2 - Incluir no final");
        printf("\n3 - mostrar");
        printf("\n5 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um numero para ser incluido: ");
            scanf("%d", &numero);
            incluir_no_inicio(l, numero);
            break;
        case 2:
            printf("\nDigite um numero para ser incluido: ");
            scanf("%d", &numero);
            incluir_no_final(l, numero);
            break;
        case 3:
            mostrar(l);
            break;
        case 5:
            printf("\n saindo do programa");
        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 5);

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
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void incluir_no_inicio(lista *l, int x)
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
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
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

void mostrar(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
    {
        printf("\nLista vazia");
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
