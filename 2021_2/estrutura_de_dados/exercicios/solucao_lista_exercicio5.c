#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} fila;

typedef struct registro
{
    int valor;
    struct registro *ant;
    struct registro *prox;
} registro;

fila *aloca_lista_dupla()
{
    fila *novo;
    novo = (fila *)calloc(1, sizeof(fila));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

// tipo_inclusao 1 : do inicio pro fim
// tipo_inclusao 2 : do fim para o inicio
void incluir(fila *l, int x, int tipo_inclusao)
{
    if (l == NULL)
        return;

    if (tipo_inclusao != 1 && tipo_inclusao != 2)
    {
        printf("\n Tipo de inclusao informado incorreto");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        switch (tipo_inclusao)
        {
        case 1:
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
            break;
        case 2:
            l->fim->prox = novo;
            novo->ant = l->fim;
            l->fim = novo;
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }
    l->qtd++;
}

void push(fila *f, int x)
{
    incluir(f, x, 2);
}

void mostrar(fila *l, int tipo_mostrar)
{
    if (l == NULL)
    {
        printf("\n Lista nao alocada");
        return;
    }

    if (tipo_mostrar != 1 && tipo_mostrar != 2)
    {
        printf("\n Tipo mostrar invalido");
        return;
    }

    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux;

    switch (tipo_mostrar)
    {
    case 1:
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->prox;
        }
        break;
    case 2:
        aux = l->fim;
        while (aux != NULL)
        {
            printf("\n -> %d", aux->valor);
            aux = aux->ant;
        }
        break;
    default:
        printf("\n opcao invalida");
        break;
    }
}

int pop(fila *f)
{
    if (f == NULL)
        return 0;
    if (f->inicio == NULL)
        return 0;

    registro *aux;
    int retorno;

    aux = f->inicio;

    if (aux->ant == NULL)
        f->inicio = aux->prox;
    else
        aux->ant->prox = aux->prox;

    if (aux->prox == NULL)
        f->fim = aux->ant;
    else
        aux->prox->ant = aux->ant;

    f->qtd--;
    retorno = aux->valor;
    free(aux);
    return retorno;
}

int stackpop(fila *f)
{
    if (f == NULL)
        return 0;
    if (f->inicio == NULL)
        return 0;
    return f->inicio->valor;
}

int main()
{

    fila *f1;

    f1 = aloca_lista_dupla();

    int valor, i, aux;

    do
    {
        scanf("%d", &valor);

        if (valor != 0)
        {
            for (i = 1; i <= valor; i++)
            {
                push(f1, i);
            }

            printf("Discarded cards:");
            while (f1->qtd >= 2)
            {
                if (f1->qtd == valor)
                    printf(" %d", pop(f1));
                else
                    printf(", %d", pop(f1));


                aux = pop(f1);
                push(f1, aux);
            }

            printf("\nRemaining card: %d\n", pop(f1));
        }

    } while (valor != 0);
    return 0;
}
