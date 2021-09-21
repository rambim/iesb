#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int valor;
} pilha;

typedef struct fila
{
    int valor;
} fila;

int main()
{
    // pilha * p1;
    return 0;
}

void inverte_fila(pilha *p, fila *f)
{

    int retorno;
    while (!empty_fila())
    {
        retorno = pop_fila(f);
        push_pilha(p, retorno);

        // push_pilha(p,pop_fila(f));
    }

    while (!empty_pilha())
    {
        retorno = pop_pilha(p);
        push_fila(f, retorno);

        // push_pilha(p,pop_fila(f));
    }

    return;
}

void push_pilha(pilha *p, int x)
{
    return;
}

int pop_pilha(pilha *p)
{
    return 0;
}

void push_fila(fila *p, int x)
{
    return;
}

int pop_fila(fila *f)
{
    return 0;
}