// Implemente um programa que possua uma função de nome "inverter_listas".
// Essa função recebe por parâmetro duas listas duplamente ligadas (lista_a, lista_b) e
// troque os valores da lista_a pelos valores invertidos da  lista_b e os valores da lista_b
// pelos valores invertidos da lista_a. Ex: Lista_a: 1,2,3 , Lista_b: 4,5,6.
// Resultado: Lista_a: 6,5,4 Lista_B: 3,2,1. Na sua função principal leia 2 números N e M que
// correspondem a quantidade de elementos da lista_a e lista_b respectivamente. Leia N + M números,
// atribua-os a suas respectivas listas e utilizando a função criada, mostre seus valores invertidos.

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
void inverter_listas(lista *l1, lista * l2);

int main()
{
    lista *la, *lb;
    int n, m, i,x;

    la = aloca_lista();
    lb = aloca_lista();

    printf("\n Digite a quantidade de elementos da primeira lista: ");
    scanf("%d", &n);

    printf("\n Digite os N elementos da primeira lista: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
        incluir_no_final(la,x);
    }
    printf("\n Digite a quantidade de elementos da segunda lista: ");
    scanf("%d", &n);

    printf("\n Digite os N elementos da primeira lista: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
        incluir_no_final(lb,x);
    }

    printf("\n Lista a: ");
    mostrar(la);
    printf("\n Lista b: ");
    mostrar(lb);

    inverter_listas(la,lb);
    printf("\n invertido: ");
    printf("\n Lista a: ");
    mostrar(la);
    printf("\n Lista b: ");
    mostrar(lb);





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
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
}

void mostrar(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
}


void inverter_listas(lista *l1, lista * l2)
{
    lista * l3;
    l3 = aloca_lista();

    registro * aux;
    aux = l1->fim;
    while(aux!=NULL)
    {
        incluir_no_final(l3,aux->valor);
        aux = aux->ant;
    }

    l1->inicio = NULL;
    l1->fim    = NULL;

    aux = l2->fim;
    while(aux!=NULL)
    {
        incluir_no_final(l1,aux->valor);
        aux = aux->ant;
    }

    aux = l3->inicio;
    l2->inicio = NULL;
    l2->fim = NULL;

    while(aux!=NULL)
    {
        incluir_no_final(l2,aux->valor);
        aux = aux->prox;
    }

}