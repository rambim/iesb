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

void mostrar(lista *l);
lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
int remover_registro(lista *l, int x);
registro *buscar(lista *l, int x);
void menu(lista *l);
lista **separa(lista *l);

int main()
{

    lista *l1, *l2, *l3;

    lista **retorno;

    l1 = aloca_lista();
    menu(l1);

    retorno = separa(l1);
    l2 = retorno[0];
    l3 = retorno[1];

    printf("\n Pares:");
    mostrar(l2);
    printf("\n Impares:");
    mostrar(l3);

    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->inicio = NULL;
    novo->qtd = 0;
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

void incluir(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0) // if(l->inicio==NULL)
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

void mostrar(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n valor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}

int remover_registro(lista *l, int x)
{
    registro *aux = NULL, *ant = NULL;

    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
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
                return 1;
            }
            else
            {
                ant = aux;
                aux = aux->prox;
            }
        }
        return 0;
    }
}

registro *buscar(lista *l, int x)
{
    registro *aux;

    if (l->inicio == NULL)
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

void menu(lista *l)
{
    int opcao;
    int numero;
    int retorno;
    registro *aux;

    do
    {
        printf("\n 1 - Incluir");
        printf("\n 2 - Buscar");
        printf("\n 3 - Remover");
        printf("\n 4 - Mostrar");
        printf("\n 5 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            incluir(l, numero);
            break;
        case 2:
            printf("\n Qual numero deseja buscar: ");
            scanf("%d", &numero);
            aux = buscar(l, numero);
            if (aux == NULL)
            {
                printf("\n numero nao encontrado");
            }
            else
            {
                printf("\n Numero %d encontrado", aux->valor);
            }

            break;

        case 3:
            printf("\n QUal numero deseja remover: ");
            scanf("%d", &numero);
            retorno = remover_registro(l, numero);
            if (retorno == 0)
            {
                printf("\n numero nao esta na lista\n");
            }
            else
            {
                printf("\n numero removido com sucesso");
            }

            break;
        case 4:
            mostrar(l);
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

lista **separa(lista *l)
{
    lista **retorno;
    registro *aux;
    retorno = (lista **)malloc(sizeof(lista *) * 2);
    retorno[0] = aloca_lista();
    retorno[1] = aloca_lista();

    aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->valor % 2 == 0)
        {
            incluir(retorno[0], aux->valor);
        }
        else
        {
            incluir(retorno[1], aux->valor);
        }
        aux=aux->prox;
    }
    return retorno;
}