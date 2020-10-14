#include <stdio.h>
#include <stdlib.h>


typedef struct lista_ligada
{
    struct registro * inicio;
    struct registro * fim;
    int qtd;
}lista_ligada;

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;

void mostrar(lista_ligada l);
int buscar_na_lista(lista_ligada l, int x);
int incluir_final_lista(lista_ligada * l, int x);
registro * aloca_registro();
lista_ligada * aloca_lista_ligada();

int main()
{
    lista_ligada * l1;
    l1 = aloca_lista_ligada();
    incluir_final_lista(l1,1);
    incluir_final_lista(l1,2);
    incluir_final_lista(l1,3);
    incluir_final_lista(l1,4);
    incluir_final_lista(l1,5);
    mostrar(*l1);
    return 0;
}

lista_ligada * aloca_lista_ligada()
{
    lista_ligada * novo;
    novo = (lista_ligada*)malloc(sizeof(lista_ligada));
    novo->inicio=NULL;
    novo->fim=NULL;
    novo->qtd =0;
    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo = (registro*)malloc(sizeof(registro));
    novo->valor=0;
    novo->prox=NULL;
    return novo;
}

int incluir_final_lista(lista_ligada * l, int x)
{
    registro * novo;
    novo = aloca_registro();
    if (novo==NULL)
    {
        return -1;
    }
    novo->valor = x;
    if (l->inicio==NULL && l->fim==NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        l->fim = novo;
    }

    return 1;
    
}

int buscar_na_lista(lista_ligada l, int x)
{
    registro * aux;
    aux = l.inicio;
    while(aux!=NULL)
    {
        if (aux->valor==x)
        {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void mostrar(lista_ligada l)
{
    registro * aux;
    aux = l.inicio;
    while(aux!=NULL)
    {
        printf("\n %d",aux->valor);
        aux = aux->prox;
    }
}

