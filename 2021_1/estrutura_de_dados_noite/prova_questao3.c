// Implemente um programa que possua uma função de nome "inverter_listas".
// Essa função recebe por parâmetro duas listas duplamente ligadas (lista_a, lista_b)
// e troque os valores da lista_a pelos valores invertidos da  lista_b e os valores da
// lista_b pelos valores invertidos da lista_a. Ex: Lista_a: 1,2,3 , Lista_b: 4,5,6.
// Resultado: Lista_a: 6,5,4 Lista_B: 3,2,1. Na sua função principal leia 2 números N
// e M que correspondem a quantidade de elementos da lista_a e lista_b respectivamente.
// Leia N + M números, atribua-os a suas respectivas listas e utilizando a função criada,
// mostre seus valores invertidos.

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
void mostrar(lista *l);
void reseta_lista(lista *l);
void inverter_listas(lista *a, lista *b);

int main()
{
    int n, m, i, numero;

    lista *l1, *l2;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("\n Quantos elemento deseja inserir na primeira lista?: ");
    scanf("%d", &n);

    printf("\n Digite os %d numeros: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        incluir_no_final(l1, numero);
    }
    printf("\n Quantos elemento deseja inserir na segunda lista?: ");
    scanf("%d", &n);

    printf("\n Digite os %d numeros: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        incluir_no_final(l2, numero);
    }

    printf("\n Mostrando primeira lista: ");
    mostrar(l1);
    printf("\n Mostrando segunda lista: ");
    mostrar(l2);

    inverter_listas(l1,l2);

    printf("\n Mostrando primeira lista: ");
    mostrar(l1);
    printf("\n Mostrando segunda lista: ");
    mostrar(l2);

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
        novo->ant = l->fim;
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void mostrar(lista *l)
{
    registro *aux;
    aux = l->inicio;
    while (aux != NULL)
    {
        printf("\n %d", aux->valor);
        aux = aux->prox;
    }
}

void inverter_listas(lista *a, lista *b)
{
    lista *l3;
    registro *aux;
    l3 = aloca_lista();

    aux = a->fim;
    while (aux != NULL)
    {
        incluir_no_final(l3, aux->valor);
        aux = aux->ant;
    }

    reseta_lista(a);
    aux = b->fim;
    while (aux != NULL)
    {
        incluir_no_final(a, aux->valor);
        aux = aux->ant;
    }
    reseta_lista(b);
    b->inicio = l3->inicio;
    b->fim    = l3->fim;

}

void reseta_lista(lista *l)
{
    if (l->inicio == NULL && l->fim == NULL)
        return;
    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        free(ant);
        ant = aux;
        aux = aux->prox;
    }
    free(ant);
    l->inicio=NULL;
    l->fim=NULL;
}