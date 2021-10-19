/*

Implemente um programa que possua uma função de nome "inverter_listas". Essa função recebe por parâmetro duas 
listas duplamente ligadas (lista_a, lista_b) e troque os valores da lista_a pelos valores invertidos 
da  lista_b e os valores da lista_b pelos valores invertidos da lista_a. Ex: Lista_a: 1,2,3 , 
Lista_b: 4,5,6. Resultado: Lista_a: 6,5,4 Lista_B: 3,2,1. Na sua função principal leia 2 números N e M 
que correspondem a quantidade de elementos da lista_a e lista_b respectivamente. Leia N + M números, 
atribua-os a suas respectivas listas e utilizando a função criada, mostre seus valores invertidos.


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_duplamente_ligada
{
    struct registro * inicio;
    struct registro * fim;
}lista_duplamente_ligada;

typedef struct registro
{
    int valor;
    struct registro * prox;
    struct registro * ant;
}registro;

void mostrar(lista_duplamente_ligada * l);
void incluir_no_final(lista_duplamente_ligada * l, int x);
registro *aloca_registro();
lista_duplamente_ligada *aloca_lista();
void inverter_listas(lista_duplamente_ligada * a, lista_duplamente_ligada * b);

int main()
{

    int n,m,i,numero;

    printf("\n Digite N: ");
    scanf("%d",&n);
    printf("\n Digite M: ");
    scanf("%d",&m);

    lista_duplamente_ligada * l1,*l2;
    l1 = aloca_lista();
    l2 = aloca_lista();

    i = n;
    printf("\n Digite %d numeros: ",n);
    while(i--)
    {
        scanf("%d",&numero);
        incluir_no_final(l1,numero);

    }

    i = m;
    printf("\n Digite %d numeros: ",m);
    while(i--)
    {
        scanf("%d",&numero);
        incluir_no_final(l2,numero);

    }

    inverter_listas(l1,l2);

    printf("\n Mostrando lista a: ");
    mostrar(l1);
    printf("\n Mostrando lista b: ");
    mostrar(l2);

    printf("\n");
    return 0;
}

lista_duplamente_ligada *aloca_lista()
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

void incluir_no_final(lista_duplamente_ligada * l, int x)
{
    if (l==NULL)
        return;

    registro * novo;
    novo = aloca_registro();

    novo->valor = x;
    
    if (l->inicio==NULL && l->fim==NULL)
    {
        l->inicio=novo;
        l->fim=novo;
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
}

void mostrar(lista_duplamente_ligada * l)
{
    if (l==NULL)
        return;

    registro * aux;

    aux = l->inicio;
    while(aux!=NULL)
    {
        printf("%d",aux->valor);
        aux = aux->prox;
    }
}

void inverter_listas(lista_duplamente_ligada * a, lista_duplamente_ligada * b)
{
    lista_duplamente_ligada * lista_aux1, *lista_aux2;

    lista_aux1 = aloca_lista();
    lista_aux2 = aloca_lista();

    registro * aux,*deletado;

    aux = a->fim;

    while(aux!=NULL)
    {
        incluir_no_final(lista_aux1,aux->valor);
        deletado = aux;
        aux = aux->ant;
        free(deletado);
    }

    aux = b->fim;

    while(aux!=NULL)
    {
        incluir_no_final(lista_aux2,aux->valor);
        deletado = aux;
        aux = aux->ant;
        free(deletado);
    }

    a->inicio = lista_aux2->inicio;
    a->fim = lista_aux2->fim;

    b->inicio=lista_aux1->inicio;
    b->fim=lista_aux1->fim;

}

