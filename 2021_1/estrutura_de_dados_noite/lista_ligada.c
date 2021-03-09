#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
}lista;

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;


lista * aloca_lista();
registro * aloca_registro();
void incluir_no_final(lista * l, int x);
void mostrar_lista(lista * l);


int main()
{
    lista * l1;

    l1 = aloca_lista();
    incluir_no_final(l1,10);
    incluir_no_final(l1,20);
    incluir_no_final(l1,30);
    incluir_no_final(l1,60);
    incluir_no_final(l1,50);
    incluir_no_final(l1,40);
    mostrar_lista(l1);

    printf("\n");
    return 0;
}

lista * aloca_lista()
{
    lista * novo;
    novo =(lista*)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio=NULL;
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

void incluir_no_final(lista * l, int x)
{
    registro * novo,*aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    l->qtd++;
}


void mostrar_lista(lista * l)
{
    registro * aux;

    if (l->inicio==NULL)
    {
        printf("\n lista vazia");
    }  
    else
    {
        aux = l->inicio;

        while(aux!=NULL)
        {
            printf("\n Valor: %d",aux->valor);
            aux = aux->prox;
        }
    }
}