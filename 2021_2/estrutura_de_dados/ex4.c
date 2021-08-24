#include <stdio.h>
#include <stdlib.h>

typedef struct lista_ligada
{
    int qtd;
    struct registro *inicio;
} lista_ligada;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista_ligada *aloca_lista();
registro *aloca_registro();
void incluir_no_fim_da_lista(lista_ligada *l, int x);
void mostrar_lista(lista_ligada *l);
int remover_registro_da_lista( lista_ligada *l, int valor_para_apagar);
void incluir_no_inicio_da_lista(lista_ligada *l, int x);
void menu(lista_ligada *l);
int buscar_registro2(lista_ligada *l, int x);
registro *buscar_registro(lista_ligada *l, int x);

int main()
{
    lista_ligada *l1;
    l1 = aloca_lista();
    menu(l1);
    return 0;
}

lista_ligada *aloca_lista()
{
    lista_ligada *novo;
    novo = (lista_ligada *)calloc(1, sizeof(lista_ligada));
    novo->inicio = NULL;

    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_no_inicio_da_lista(lista_ligada *l, int x)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
        l->inicio = novo;
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}
void incluir_no_fim_da_lista(lista_ligada *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
        l->inicio = novo;
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

void mostrar_lista(lista_ligada *l)
{
    if (l == NULL)
    {
        printf("\n Lista nao alocada");
        return;
    }

    if (l->inicio == NULL)
    {
        printf("\n Lista sem elementos");
        return;
    }

    registro *aux;

    aux = l->inicio;

    while (aux != NULL)
    {
        printf("\n -> %d", aux->valor);
        aux = aux->prox;
    }
}

//0 - não conseguir apagar um elemento.
//1 - conseguir apagar um elemento.

int remover_registro_da_lista( lista_ligada *l, int valor_para_apagar)
{
    if (l == NULL)
    {
        printf("\nLista inexistente");
        return 0;
    }

    if (l->inicio == NULL)
    {
        printf("\nLista vazia");
        return 0;
    }

    registro *aux = l->inicio, *ant = NULL;
    int encontrou = 0;
    while (aux != NULL && encontrou == 0)
    {
        if (aux->valor == valor_para_apagar)
        {

            if (ant == NULL)
                l->inicio = aux->prox;
            else
                ant->prox = aux->prox;

            free(aux);
            l->qtd--;
            encontrou = 1;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    if (encontrou)
        return 1;
    else
        return 0;
}

registro *buscar_registro(lista_ligada *l, int x)
{
    if (l == NULL)
        return NULL;
    if (l->inicio == NULL)
        return NULL;

    registro *aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

int buscar_registro2(lista_ligada *l, int x)
{
    if (l == NULL)
        return 0;
    if (l->inicio == NULL)
        return 0;

    registro *aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
            return aux->valor;
        aux = aux->prox;
    }
    return 0;
}

void menu(lista_ligada *l)
{
    int opcao, numero, aux2;
    registro *aux;

    do
    {
        printf("\n 1 - Incluir no inicio da lista");
        printf("\n 2 - Incluir no final da lista");
        printf("\n 3 - Buscar numero na lista");
        printf("\n 4 - Remover numero da lista");
        printf("\n 5 - Mostrar lista");
        printf("\n 10 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite o numero que deseja inserir: ");
            scanf("%d", &numero);
            incluir_no_inicio_da_lista(l, numero);
            break;
        case 2:
            printf("\n Digite o numero que deseja inserir: ");
            scanf("%d", &numero);
            incluir_no_fim_da_lista(l, numero);
            break;
        case 3:
            printf("\n Digite o numero que deseja buscar: ");
            scanf("%d", &numero);
            aux = buscar_registro(l, numero);
            aux2 = buscar_registro2(l, numero);
            if (aux == NULL)
                printf("\n Numero nao encontrado");
            else
                printf("\n Numero encontrado: %d", aux->valor);

            if (aux2 != 0)
                printf("\n Numero encontrado: %d", aux2);
            else
                printf("\n Numero nao encontrado.");

            break;
        case 4:
            printf("\n Digite o numero que deseja remover: ");
            scanf("%d",&numero);
            if(remover_registro_da_lista(l,numero))
                printf("\n Numero removido com sucesso");
            else
                printf("\n Numero nao existe na lista");

            break;
        case 5:
            mostrar_lista(l);
            break;
        case 10:
            printf("\n Saindo do programa\n");
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    } while (opcao != 10);
}