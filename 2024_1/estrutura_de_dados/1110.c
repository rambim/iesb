#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    struct registro *inicio;
    struct registro *fim;
    int qtd;
} fila;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

int remover_fila(fila *f);
fila *cria_fila();
registro *cria_registro();
void inserir_fila(fila *f, int valor);

int main()
{
    fila *f;
    f = cria_fila();

    int n, i, aux;

    do
    {

        int roubei = 0;
        scanf("%d", &n);

        if (n != 0)
        {

            for (i = 1; i <= n; i++)
            {
                inserir_fila(f, i);
            }
            printf("Discarded cards: ");
            while (f->qtd >= 2)
            {
                if (roubei == 0)
                {
                    printf("%d", remover_fila(f));
                    roubei++;
                }
                else
                {
                    printf(", %d", remover_fila(f));
                }
                aux = remover_fila(f);
                inserir_fila(f, aux);
            }
            printf("\n");

            printf("Remaining card: %d\n", remover_fila(f));
        }

    } while (n != 0);

    return 0;
}

fila *cria_fila()
{
    return (fila *)calloc(1, sizeof(fila));
}

registro *cria_registro()
{
    return (registro *)calloc(1, sizeof(registro));
}

void inserir_fila(fila *f, int valor)
{
    registro *novo;
    novo = cria_registro();
    novo->valor = valor;

    if (f->inicio == NULL && f->fim == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtd++;
}

int remover_fila(fila *f)
{
    if (f->inicio == NULL && f->fim == NULL)
    {
        return -1;
    }
    else
    {
        registro *aux;
        int retorno;
        aux = f->inicio;
        f->inicio = aux->prox;
        retorno = aux->valor;
        free(aux);
        if (f->inicio == NULL)
        {
            f->fim = NULL;
        }
        f->qtd--;
        return retorno;
    }
}