

#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int tamanho;
    struct elemento *inicio;
    struct elemento *fim;
} fila;

typedef struct elemento
{
    int valor;
    struct elemento *prox;
} elemento;

fila *aloca_fila();
elemento *aloca_elemento();
void insert(fila *f, int x);
int dequeue(fila *f);
int empty(fila *f);
int size(fila *f);
int front(fila *f);
void menu(fila *f);

int main()
{
    int n = 1;
    int i;
    fila *f;
    int numero;
    while (n != 0)
    {
        f = aloca_fila();
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            insert(f, i);
        }

        printf("\nDiscarded cards: ");
        while (size(f) >= 2)
        {
            numero = dequeue(f);
            printf(" %d", numero);
            numero = dequeue(f);
            insert(f, numero);
        }

        numero = dequeue(f);
        printf("\n Remaining card: %d\n",numero);
        free(f);
    }

    printf("\n");
    return 0;
}

fila *aloca_fila()
{
    fila *novo;
    novo = (fila *)calloc(1, sizeof(fila));
    return novo;
}

elemento *aloca_elemento()
{
    elemento *novo;
    novo = (elemento *)calloc(1, sizeof(elemento));
    return novo;
}

void insert(fila *f, int x)
{
    elemento *novo;
    novo = aloca_elemento();
    novo->valor = x;

    if (f->inicio == NULL && f->fim == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;
}

int dequeue(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
        return 0;

    int retorno;
    elemento *aux;

    aux = f->inicio;
    f->inicio = aux->prox;
    retorno = aux->valor;
    free(aux);
    f->tamanho--;
    if (f->tamanho==0)
        f->fim = NULL;
    return retorno;
}

int empty(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
        return 1;
    else
        return 0;
}

int size(fila *f)
{
    return f->tamanho;
}

int front(fila *f)
{
    return f->inicio->valor;
}
