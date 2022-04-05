// Desenva as principais funções de uma pilha utilizando a estrura de pilha
// ligada;

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int qtd;
    struct registro *topo;

} pilha;

typedef struct registro
{
    int codigo;
    struct registro *prox;

} registro;

int stackpop(pilha * l);
pilha *aloca_pilha();
registro *aloca_registro();
int empty(pilha *l);
int size(pilha *l);
void push(pilha *l, int codigo);
int pop(pilha *l);
int stackpop(pilha * l);

int main()
{

    pilha * p;
    p = aloca_pilha();
    push(p,1);
    push(p,2);
    push(p,3);
    push(p,4);

    
    printf("\nstackpop: %d ",stackpop(p));
    printf("\npop     : %d ",pop(p));
    printf("\nstackpop: %d ",stackpop(p));
    printf("\npop     : %d ",pop(p));
    printf("\nstackpop: %d ",stackpop(p));
    printf("\npop     : %d ",pop(p));
    printf("\nstackpop: %d ",stackpop(p));
    printf("\npop     : %d ",pop(p));
    printf("\nstackpop: %d ",stackpop(p));
    printf("\npop     : %d ",pop(p));
    return 0;
}

pilha *aloca_pilha()
{
    pilha *novo;
    novo = (pilha *)malloc(sizeof(pilha));
    novo->topo = NULL;
    novo->qtd = 0;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->codigo = 0;
    novo->prox = NULL;
    return novo;
}

int empty(pilha *l)
{
    if (l->topo == NULL)
        return 1;
    else
        return 0;
}

int size(pilha *l)
{
    return l->qtd;
}

void push(pilha *l, int codigo)
{
    registro * novo;
    novo = aloca_registro();
    novo->codigo = codigo;
    if (empty(l))
    {
        l->topo = novo;
    }
    else
    {
        novo->prox = l->topo;
        l->topo = novo;
    }
    l->qtd++;
}

int pop(pilha *l)
{
    registro *aux;
    int retorno = 0;
    if (!empty(l))
    {
        aux = l->topo;
        l->topo = l->topo->prox;
        retorno = aux->codigo;
        free(aux);
        l->qtd--;
    }
    return retorno;
}

int stackpop(pilha * l)
{
    if(empty(l))
        return 0;
    else{
        return l->topo->codigo;
    }
}
