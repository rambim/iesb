#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;

} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void incluir_comeco(lista *l, int x);
registro *buscar(lista *l, int x);
int remover(lista *l, int x);
void mostrar(lista *l, int opcao);
void menu(lista *l);
void juntar_listas(lista *l1, lista *l2);
void mostrar_2_listas(lista *l1, lista *l2);

int main()
{
    int opcao;
    int i;
    lista *l1, *l2;
    l1 = aloca_lista();
    l2 = aloca_lista();

    do
    {
        printf("\n 1 - CRUD lista 1");
        printf("\n 2 - CRUD lista 2");
        printf("\n 3 - juntar listas");
        printf("\n 4 - Mostrar as 2 listas");
        printf("\n 5 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu(l1);
            break;
        case 2:
            menu(l2);
            break;
        case 3:
            juntar_listas(l1, l2);
            break;
        case 4:
            mostrar_2_listas(l1, l2);
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
        }

    } while (opcao != 5);

    menu(l1);
    printf("\n");
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *aux;
    registro *novo;

    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->fim;
        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;
    }

    l->qtd++;
}

void incluir_comeco(lista *l, int x)
{
    registro *aux, *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->inicio;
        aux->ant = novo;
        novo->prox = aux;
        l->inicio = novo;
    }

    l->qtd++;
}

registro *buscar(lista *l, int x)
{
    registro *aux;

    if (l->qtd == 0)
    {
        return NULL;
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->valor == x)
            {
                return aux;
            }
            else
            {
                aux = aux->prox;
            }
        }

        return NULL;
    }
}

int remover(lista *l, int x)
{
    registro *aux, *tras, *frente;

    aux = buscar(l, x);

    if (aux == NULL)
    {
        return 0;
    }

    tras = aux->ant;
    frente = aux->prox;

    if (tras == NULL)
    {
        l->inicio = frente;
    }
    else
    {
        tras->prox = frente;
    }

    if (frente == NULL)
    {
        l->fim = tras;
    }
    else
    {
        frente->ant = tras;
    }
    free(aux);
    l->qtd--;
    return 1;
}

// 1 - indo
// 2 - vindo

void mostrar(lista *l, int opcao)
{
    registro *aux;

    if (l == NULL)
    {
        printf("\n primeiro parametro invalido");
        return;
    }
    if (opcao != 1 && opcao != 2)
    {
        printf("\n segundo parametro invalido");
        return;
    }

    if (l->qtd == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {

        if (opcao == 1)
        {
            aux = l->inicio;
        }
        else
        {
            aux = l->fim;
        }

        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            if (opcao == 1)
            {
                aux = aux->prox;
            }
            else
            {
                aux = aux->ant;
            }
        }
    }
}

void menu(lista *l)
{
    int opcao;
    int numero, retorno;
    registro *aux;

    do
    {
        printf("\n 1 - incluir no comeco");
        printf("\n 2 - incluir no final");
        printf("\n 3 - buscar");
        printf("\n 4 - remover");
        printf("\n 5 - mostrar");
        printf("\n 6 - sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir ?");
            scanf("%d", &numero);
            incluir_comeco(l, numero);

            break;
        case 2:
            printf("\n Qual numero deseja inserir ?");
            scanf("%d", &numero);
            incluir_no_final(l, numero);

            break;
        case 3:
            printf("\n Qual numero deseja buscar?");
            scanf("%d", &numero);
            aux = buscar(l, numero);
            if (aux == NULL)
            {
                printf("\n numero nao encontrado");
            }
            else
            {
                printf("\n numero %d encontrado", aux->valor);
            }

            break;
        case 4:
            printf("\n Qual numero deseja remover?");
            scanf("%d", &numero);
            retorno = remover(l, numero);
            if (retorno == 0)
            {
                printf("\n numero nao foi removido");
            }
            else
            {
                printf("\n numero removido com sucesso");
            }

            break;
        case 5:
            printf("\n Deseja mostrar indo (1) ou vindo (2)");
            scanf("%d", &numero);
            mostrar(l, numero);
            break;
        case 6:
            printf("\n saindo do programa");

            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 6);
}

void juntar_listas(lista *l1, lista *l2)
{
    if (l2->qtd == 0)
    {
        return;
    }

    if (l1->qtd = 0)
    {
        l1->qtd = l2->qtd;
        l1->inicio = l2->inicio;
        l1->fim = l2->fim;
    }
    else
    {
        l1->fim->prox = l2->inicio;
        l2->inicio->ant = l1->fim;
        l1->qtd = l1->qtd + l2->qtd;
    }

    l2->qtd = 0;
    l2->inicio = NULL;
    l2->fim = NULL;

    return;
}

void mostrar_2_listas(lista *l1, lista *l2)
{
    printf("\n Lista l1:");
    mostrar(l1, 1);
    printf("\n Lista l2:");
    mostrar(l2, 1);
    printf("\n");
}
