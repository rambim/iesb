// Desenva as principais funções de uma fila utilizando a estrura de fila
// ligada;

#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int qtd;
    struct registro *inicio;

} fila;

typedef struct registro
{
    int codigo;
    struct registro *prox;

} registro;

int stackpop(fila * l);
fila *aloca_fila();
registro *aloca_registro();
int empty(fila *l);
int size(fila *l);
void push(fila *l, int codigo);
int pop(fila *l);
int stackpop(fila * l);

int main()
{

    fila * p;
    p = aloca_fila();
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
    printf("\n");
    return 0;
}

fila *aloca_fila()
{
    fila *novo;
    novo = (fila *)malloc(sizeof(fila));
    novo->inicio = NULL;
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

int empty(fila *l)
{
    if (l->inicio == NULL)
        return 1;
    else
        return 0;
}

int size(fila *l)
{
    return l->qtd;
}

void push(fila *l, int codigo)
{
    registro * novo;
    registro * aux;
    novo = aloca_registro();
    novo->codigo = codigo;
    if (empty(l))
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

int pop(fila *l)
{
    registro *aux;
    int retorno = 0;
    if (!empty(l))
    {
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        retorno = aux->codigo;
        free(aux);
        l->qtd--;
    }
    return retorno;
}

int stackpop(fila * l)
{
    if(empty(l))
        return 0;
    else{
        return l->inicio->codigo;
    }
}
