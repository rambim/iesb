// 1) Utilizando como base o programa lista_ligada.c, construa um programa que disponibilize ao usuario as seguintes opcoes

//     a) Incluir na lista: O usuário irá informar um número que será incluído na lista
//     b) Mostrar lista: deverá ser mostrado na tela a lista completa.
//     c) Mostrar pares da lista: deverá ser mostrado na tela apenas os números pares

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void mostrar_pares_lista(lista *l);
void mostrar_lista(lista *l);
void menu(lista *l);
void remover_da_lista(lista *l, int x);

int main()
{
    lista *l1;
    l1 = aloca_lista();
    menu(l1);
    printf("\n");
    return 0;
}

void menu(lista *l)
{
    int opcao, numero;

    do
    {
        printf("\n 1 - Incluir na lista");
        printf("\n 2 - Mostrar lista");
        printf("\n 3 - Mostrar pares da lista");
        printf("\n 4 - Remover numero: ");
        printf("\n 5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja incluir na lista? ");
            scanf("%d", &numero);
            incluir_no_final(l, numero);
            break;
        case 2:
            mostrar_lista(l);
            break;
        case 3:
            mostrar_pares_lista(l);
            break;
        case 4:
            printf("\n Qual numero deseja remover? ");
            scanf("%d",&numero);
            remover_da_lista(l,numero);
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\nValor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}
void mostrar_pares_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aux->valor % 2 == 0)
            {
                printf("\nValor = %d", aux->valor);
            }
            aux = aux->prox;
        }
    }
}

void remover_da_lista(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux = NULL, *ant = NULL;
    aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            free(aux);
            l->qtd--;
            printf("\n Numero removido");
            return;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    printf("\n Numero nao esta na lista");
    return;
}