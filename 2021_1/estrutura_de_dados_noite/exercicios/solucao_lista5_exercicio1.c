#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int qtd;
    struct elemento *topo;

} pilha;

typedef struct elemento
{
    int valor;
    struct elemento *prox;
} elemento;

pilha *aloca_pilha();
elemento *aloca_elemento();
int empty(pilha *p);
void push(pilha *p, int x);
int stackpop(pilha *p);
int pop(pilha *p);
void menu(pilha *p);
void inverter_pilha(pilha *p);
void mostrar_pilha(pilha *p);
void troca_topo_base(pilha *p);
void pares_na_base(pilha *p);

int main()
{
    pilha *p;
    p = aloca_pilha();
    menu(p);
    free(p);
    return 0;
}

pilha *aloca_pilha()
{
    pilha *novo;
    novo = (pilha *)calloc(1, sizeof(pilha));
    return novo;
}

elemento *aloca_elemento()
{
    elemento *novo;
    novo = (elemento *)calloc(1, sizeof(elemento));
    return novo;
}

int empty(pilha *p)
{
    if (p->topo == NULL)
        return 1;
    else
        return 0;
}

void push(pilha *p, int x)
{
    elemento *novo;
    novo = aloca_elemento();
    novo->valor = x;

    if (empty(p))
        p->topo = novo;
    else
    {
        novo->prox = p->topo;
        p->topo = novo;
    }
    p->qtd++;
}

int pop(pilha *p)
{
    if (empty(p))
        return -1;
    else
    {
        int retorno;
        elemento *aux;
        aux = p->topo;
        p->topo = aux->prox;
        retorno = aux->valor;
        free(aux);
        p->qtd--;
        return retorno;
    }
}

int stackpop(pilha *p)
{
    if (empty(p))
        return -1;
    else
        return p->topo->valor;
}

void menu(pilha *p)
{
    int opcao;
    int numero;

    do
    {
        printf("\n Qtd: %d", p->qtd);
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Inverter Pilha");
        printf("\n 6 - Troca topo base");
        printf("\n 7 - Pares na base");
        printf("\n 9 - Mostrar Pilha * Proibido");
        printf("\n Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite  um numero: ");
            scanf("%d", &numero);
            push(p, numero);
            break;
        case 2:
            if (empty(p))
                printf("\n Pilha vazia");
            else
                printf("\nNumero que saiu: %d", pop(p));
            break;
        case 3:
            if (empty(p))
                printf("\n Pilha vazia");
            else
                printf("\nNumero no topo: %d", stackpop(p));
            break;
        case 4:
            if (empty(p))
                printf("\n Pilha vazia");
            else
                printf("\n Pilha nao esta vazia");
            break;
        case 5:
            if (empty(p))
                printf("\n Pilha vazia");
            else
            {
                inverter_pilha(p);
                printf("\n Pilha invertida");
            }
            break;
        case 6:
            if (empty(p))
                printf("\n Pilha vazia");
            else
            {
                troca_topo_base(p);
                printf("\n Topo alterado pela base");
            }
            break;
        case 7:
            if (empty(p))
                printf("\n Pilha vazia");
            else
            {
                pares_na_base(p);
                printf("\n Pares movidos para a base");
            }
            break;
        case 9:
            mostrar_pilha(p);
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 10);
}

void inverter_pilha(pilha *p)
{
    int *vet;
    vet = (int *)calloc(p->qtd, sizeof(int));
    int i = 0;

    while (!empty(p))
    {
        vet[i] = pop(p);
        i++;
    }
    int n;

    for (n = 0; n < i; n++)
    {
        push(p, vet[n]);
    }
    free(vet);
}

void mostrar_pilha(pilha *p)
{
    if (empty(p))
    {
        printf("\n Pilha vazia");
        return;
    }
    else
    {
        elemento *aux;
        aux = p->topo;
        while (aux != NULL)
        {
            printf("\n%d", aux->valor);
            aux = aux->prox;
        }
    }
}

void troca_topo_base(pilha *p)
{
    int topo, base;
    pilha *aux;
    aux = aloca_pilha();

    if (empty(p))
        return;
    else
    {
        topo = pop(p);
        while (!empty(p))
        {
            push(aux, pop(p));
        }

        base = pop(aux);

        push(p, topo);

        while (!empty(aux))
        {
            push(p, pop(aux));
        }
        push(p, base);
        free(aux);
    }
}

void pares_na_base(pilha *p)
{
    if (empty(p))
        return;

    pilha *pares, *impares;

    pares = aloca_pilha();
    impares = aloca_pilha();
    int numero;

    while (!empty(p))
    {
        numero = pop(p);
        if (numero % 2 == 0)
            push(pares, numero);
        else
            push(impares, numero);
    }

    while (!empty(pares))
    {
        push(p, pop(pares));
    }
    while (!empty(impares))
    {
        push(p, pop(impares));
    }
    free(pares);
    free(impares);
}