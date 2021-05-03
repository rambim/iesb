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
    fila *f1;
    int n, i, numero;

    do
    {
        scanf("%d", &n);
        f1 = aloca_fila();

        for (i = 1; i <= n; i++)
        {
            insert(f1, i);
        }

        printf("\n Descartes: ");
        while (size(f1) >= 2)
        {
            numero = dequeue(f1);
            printf("%d ", numero);
            numero = dequeue(f1);
            insert(f1, numero);
        }

        printf("\n Carta que sobrou: ");
        numero = dequeue(f1);
        printf("%d ", numero);

    } while (n != 0);

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

    if (f->inicio == NULL)
        f->fim = NULL;

    retorno = aux->valor;
    free(aux);
    f->tamanho--;
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

void menu(fila *f)
{
    int opcao, numero;

    do
    {
        printf("\n 1 - Insert");
        printf("\n 2 - Remove");
        printf("\n 3 - Empty");
        printf("\n 4 - Size");
        printf("\n 5 - Front");
        printf("\n 9 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero para ser inserido: ");
            scanf("%d", &numero);
            insert(f, numero);
            break;
        case 2:
            if (empty(f))
                printf("\n Fila vazia");
            else
            {
                numero = dequeue(f);
                printf("\n Numero chamado: %d", numero);
            }
            break;
        case 3:
            if (empty(f))
                printf("\n Fila vazia");
            else
                printf("\n Fila nao esta vazia");
            break;
        case 4:
            printf("\n Tamanho da fila: %d", size(f));
            break;
        case 5:
            if (empty(f))
                printf("\n Fila vazia");
            else
                printf("\n Proximo a ser chamado: %d", front(f));
            break;
        case 9:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    } while (opcao != 9);
}