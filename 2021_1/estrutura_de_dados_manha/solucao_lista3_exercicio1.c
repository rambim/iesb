#include <stdio.h>
#include <stdlib.h>

/*
1) Construa uma estrutura de lista duplamente ligada que permita as seguintes operações:

a) Incluir no inicio da lista
b) incluir no final da lista
c) mostrar lista
d) mostrar primos da lista
e) mostrar lista de tras pra frente
f) remover elemento da lista
g) remover primos da lista

*/

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;

} lista;

typedef struct registro
{
    int valor;
    struct registro *ant;
    struct registro *prox;
} registro;

void incluir_fim(lista *l, int x);
void incluir_inicio(lista *l, int x);
lista *aloca_lista();
registro *aloca_registro();
void mostrar(lista *l, int invertido, int primo);
int is_primo(int x);
int remover_primos(lista *l);
int remover(lista *l, int x);
void menu(lista *l);

int main()
{
    lista *l;
    l = aloca_lista();
    menu(l);
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_fim(lista *l, int x)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
    l->qtd++;
}
void incluir_inicio(lista *l, int x)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL && l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void mostrar(lista *l, int invertido, int primo)
{
    if (l->inicio == NULL && l->fim == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux;

    if (!invertido)
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            if (primo)
            {
                if (is_primo(aux->valor))
                {
                    printf("\n%d", aux->valor);
                }
            }
            else
            {
                printf("\n%d", aux->valor);
            }
            aux = aux->prox;
        }
    }
    else
    {
        aux = l->fim;
        while (aux != NULL)
        {
            if (primo)
            {
                if (is_primo(aux->valor))
                {
                    printf("\n%d", aux->valor);
                }
            }
            else
            {
                printf("\n%d", aux->valor);
            }
            aux = aux->ant;
        }
    }
}

int is_primo(int x)
{
    if (x == 0 || x == 1)
        return 0;

    int div;

    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
        {
            return 0;
        }
    }
    return 1;
}

int remover(lista *l, int x)
{
    if (l->inicio == NULL && l->fim == NULL)
    {
        printf("\n Lista vazia");
        return 0;
    }

    registro *aux, *anterior, *proximo, *apagado;
    aux = l->inicio;

    while (aux != NULL)
    {

        if (aux->valor == x)
        {
            apagado = aux;
            anterior = aux->ant;
            proximo = aux->prox;

            if (anterior == NULL)
            {
                l->inicio = proximo;
            }
            else
            {
                anterior->prox = proximo;
            }

            if (proximo == NULL)
            {
                l->fim = anterior;
            }
            else
            {
                proximo->ant = anterior;
            }

            if (anterior == NULL)
            {
                aux = l->inicio;
            }
            else
            {
                aux = anterior->prox;
            }
            free(apagado);
            l->qtd--;
        }
        else
        {
            aux = aux->prox;
        }
    }
}

int remover_primos(lista *l)
{
    if (l->inicio == NULL && l->fim == NULL)
    {
        printf("\n Lista vazia");
        return 0;
    }

    registro *aux, *anterior, *proximo, *apagado;
    aux = l->inicio;

    while (aux != NULL)
    {

        if (is_primo(aux->valor))
        {
            apagado = aux;
            anterior = aux->ant;
            proximo = aux->prox;

            if (anterior == NULL)
            {
                l->inicio = proximo;
            }
            else
            {
                anterior->prox = proximo;
            }

            if (proximo == NULL)
            {
                l->fim = anterior;
            }
            else
            {
                proximo->ant = anterior;
            }
            if (anterior == NULL)
            {
                aux = l->inicio;
            }
            else
            {
                aux = anterior->prox;
            }
            free(apagado);
            l->qtd--;
        }
        else
        {
            aux = aux->prox;
        }
    }
}

void menu(lista *l)
{
    int opcao;
    int numero;

    do
    {
        printf("\n 1 - Incluir no inicio da lista");
        printf("\n 2 - incluir no final da lista");
        printf("\n 3 - mostrar lista");
        printf("\n 4 - mostrar primos da lista");
        printf("\n 5 - mostrar lista de tras pra frente");
        printf("\n 6 - remover elemento da lista");
        printf("\n 7 - remover primos da lista");
        printf("\n 10 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um numero: ");
            scanf("%d", &numero);
            incluir_inicio(l, numero);
            break;
        case 2:
            printf("\nDigite um numero: ");
            scanf("%d", &numero);
            incluir_fim(l, numero);
            break;
        case 3:
            mostrar(l, 0, 0);
            break;
        case 4:
            mostrar(l, 0, 1);
            break;
        case 5:
            mostrar(l, 1, 0);
            break;
        case 6:
            printf("\nDigite um numero para ser removido: ");
            scanf("%d", &numero);
            remover(l, numero);
            break;
        case 7:
            remover_primos(l);
            break;
        case 10:
            break;
        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 10);
}

// a) Incluir no inicio da lista
// b) incluir no final da lista
// c) mostrar lista
// d) mostrar primos da lista
// e) mostrar lista de tras pra frente
// f) remover elemento da lista
// g) remover primos da lista