#include <stdio.h>
#include <stdlib.h>


typedef struct pilha{
    struct registro * topo;
}pilha;

typedef struct registro{
    int valor;
    struct registro * prox;
}registro;


pilha * cria_pilha();
registro * cria_registro();
void push(pilha * p, int valor);
int pop(pilha * p );
int stackpop(pilha * p);
int empty(pilha * p);


int main()
{

    pilha * p = cria_pilha();

    int i=50;

    while(i--)
    {
        push(p,i);
    }

    
    while(!empty(p))
    {
        printf("\n Esta no topo: %d",stackpop(p));
        printf("\n Saiu do topo: %d",pop(p));
    }
    return 0;
}

pilha * cria_pilha()
{
    return (pilha*)calloc(1,sizeof(pilha));
}

registro * cria_registro()
{
    return (registro*)calloc(1,sizeof(registro));
}

void push(pilha * p, int valor)
{
    registro * novo = cria_registro();
    novo->valor = valor;
    if (empty(p))
    {
        p->topo = novo;
    }
    else
    {
        novo->prox = p->topo;
        p->topo = novo;
    }
}

int pop(pilha * p )
{
    int retorno;

    if (empty(p))
    {
        return 0;
    }
    else
    {
        retorno = p->topo->valor;
        p->topo = p->topo->prox;
        return retorno;
    }
}

int stackpop(pilha * p)
{
    if (empty(p))
    {
        return 0;
    }
    else
    {
        return p->topo->valor;
    }
}

int empty(pilha * p)
{
    if (p->topo==NULL)
        return 1;
    else
        return 0;
}

