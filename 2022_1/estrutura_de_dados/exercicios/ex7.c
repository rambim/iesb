#include <stdio.h>
#include <stdlib.h>

typedef struct lista_dupla
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} lista_dupla;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

void incluir(lista_dupla *l, int x, int flag);
void mostrar_lista(lista_dupla *l);
lista_dupla *aloca_lista();
registro *aloca_registro();
int mais_perto(lista_dupla *l, int x);

int main()
{

    int flag = 1;
    int n;
    int i;
    int numero;
    lista_dupla *l;
    l = aloca_lista();

    printf("\n Digite N: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d", &numero);
        incluir(l, numero, flag);
        if (flag == 1)
            flag = 2;
        else
            flag = 1;
    }

    mostrar_lista(l);

    while (numero != 0)
    {

        printf("\n Digite o numero para saber qual local mais perto: ");
        scanf("%d", &numero);
        switch (mais_perto(l, numero))
        {
        case 0:
            printf("\n Nao esta na lista");
            break;
        case 1:
            printf("\n Meio");
            break;
        case 2:
            printf("\n Inicio");
            break;
        case 3:
            printf("\n Final");
            break;
        default:
            printf("\n retorno invalido");
            break;
        }
    }

    printf("\n");
    return 0;
}

lista_dupla *aloca_lista()
{
    lista_dupla *novo;
    novo = (lista_dupla *)malloc(sizeof(lista_dupla));
    novo->fim = NULL;
    novo->inicio = NULL;
    novo->qtd = 0;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->valor = 0;
    return novo;
}

// flag == 1 ( incluir no inicio)
// flag == 2 ( incluir no final)
void incluir(lista_dupla *l, int x, int flag)
{
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
        switch (flag)
        {
        case 1:
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
            break;
        case 2:
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;
            break;
        default:
            printf("\n Parametro informado invalido");
            return;
            break;
        }
    }
    l->qtd++;
}

void mostrar_lista(lista_dupla *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    aux = l->inicio;
    while (aux != NULL)
    {
        printf(" %d", aux->valor);
        aux = aux->prox;
    }
}

// 0 : nao existe na lista
// 1 : meio
// 2 : inicio
// 3 : fim
int mais_perto(lista_dupla *l, int x)
{
    if (l->inicio == NULL)
        return 0;

    registro *aux;
    int cont = 1;
    int meio = 0;

    aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            meio = (l->qtd / 2) + 1;

            if (l->qtd % 2 == 0)
            {
                if (cont < meio)
                {
                    return 2;
                }
                else
                {
                    return 3;
                }
            }
            else
            {
                if (cont < meio)
                    return 2;
                if (cont == meio)
                    return 1;
                if (cont > meio)
                    return 3;
            }
        }
        aux = aux->prox;
        cont++;
    }
    return 0;
}