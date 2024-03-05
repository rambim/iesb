#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    struct registro *inicio;
    int qtd;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

void mostrar_lista(lista *l);
lista *cria_lista();
registro *cria_registro();
void menu(lista *l);
void inserir_ordenado(lista *l, int valor);

int main(char argc, char *argv[])
{
    lista *a;
    a = cria_lista();
    menu(a);

    return 0;
}

lista *cria_lista()
{
    lista *nova_lista;
    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;
    return nova_lista;
}

registro *cria_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void mostrar_lista(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n Nao existem elementos nessa lista");
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\n Valor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void inserir_ordenado(lista *l, int valor)
{

    registro *novo = NULL;
    registro *aux = NULL;
    registro *ant = NULL;
    novo = cria_registro();
    novo->valor = valor;

    if (l->inicio == NULL)
    {

        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;

        // while (novo->valor > aux->valor && aux->prox != NULL)
        // {
        //     ant = aux;
        //     aux = aux->prox;
        // }

        // if (ant ==NULL)
        // {
            
        // }

    }
}

void menu(lista *l)
{
    int opcao;
    int numero;

    do
    {
        printf("\n 1 - Incluir Ordenado");
        printf("\n 5 - Mostrar lista");
        printf("\n 10 - sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite o numero que deseja inserir:");
            scanf("%d", &numero);
            inserir_ordenado(l, numero);
            break;

        case 5:
            mostrar_lista(l);
            break;
        case 10:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 10);

    printf("\n");
}