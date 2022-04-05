#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{

    int valor;
    struct registro *prox;
} registro;
typedef struct lista
{
    int qtd;
    struct registro *inicio;

} lista;

void mostrar_lista(lista *l);
lista *aloca_lista();
registro *aloca_registro();
void incluir_registro_inicio(lista *l, int numero);
void incluir_registro_final(lista *l, int numero);
int buscar(lista *l, int numero);
void menu(lista *l);
int remover(lista *l, int numero);
void concatena_listas(lista * l1, lista * l2);

int main()
{
    lista *l1, *l2;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("\n Menu Lista 1");
    menu(l1);
    
    printf("\n Menu Lista 2");
    menu(l2);

    printf("\n Mostrando l1:");
    mostrar_lista(l1);

    printf("\n Mostrando l2:");
    mostrar_lista(l2);

    printf("\n Concatenando Listas");
    concatena_listas(l1,l2);

    printf("\n Mostrando l1:");
    mostrar_lista(l1);

    printf("\n Mostrando l2:");
    mostrar_lista(l2);
    return 0;
}

void menu(lista *l)
{
    int opcao;
    int numero;

    do
    {
        printf("\n 01 - Incluir no inicio");
        printf("\n 02 - Incluir no final");
        printf("\n 03 - Mostrar lista");
        printf("\n 04 - Buscar numero");
        printf("\n 05 - Remover numero");
        printf("\n 10 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero:");
            scanf("%d", &numero);
            incluir_registro_inicio(l, numero);
            break;
        case 2:
            printf("\n Digite um numero:");
            scanf("%d", &numero);
            incluir_registro_final(l, numero);
            break;
        case 3:
            mostrar_lista(l);
            break;
        case 4:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);

            if (buscar(l, numero))
            {
                printf("\n Numero encontrado");
            }
            else
            {
                printf("\n Numero nao esta na lista");
            }
            break;
        case 5:
            printf("\n Digite um numero: ");
            scanf("%d",&numero);
            if (remover(l,numero))
            {
                printf("\n numero removido ");
            }
            else
            {
                printf("\n numero nao removido ou lista vazia");
            }
            break;
        case 10:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }

    } while (opcao != 10);
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

void incluir_registro_inicio(lista *l, int numero)
{
    registro *novo;
    novo = aloca_registro();

    novo->valor = numero;

    if (l->inicio == NULL)
    {

        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_registro_final(lista *l, int numero)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = numero;

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
    registro *aux;
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {

        printf("\n Qtd elementos na lista: %d\n",l->qtd);
        aux = l->inicio;
        while (aux != NULL)
        {
            printf(" %d", aux->valor);
            aux = aux->prox;
        }
    }
}

int buscar(lista *l, int numero)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        registro *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->valor == numero)
            {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

int remover(lista *l, int numero)
{
    if (l->inicio == NULL)
    {
        return 0;
    }
    else
    {
        registro *aux = NULL, *ant = NULL;
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aux->valor == numero)
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
            ant = aux;
            aux = aux->prox;
        }
    }
}

void concatena_listas(lista * l1, lista * l2)
{
    if (l1->inicio==NULL && l2->inicio==NULL)
    {
        printf("\n Nenhum das listas existem");
        return;
    }
    else
    {
        if (l1->inicio==NULL)
        {
            l1->inicio = l2->inicio;
            l1->qtd = l2->qtd;
            l2->inicio=NULL;
            l2->qtd=0;
            return;
        }
        else
        {
            if (l2->inicio==NULL)
                return;
            else
            {
                registro * aux;
                aux = l1->inicio;
                while(aux->prox!=NULL)
                    aux = aux->prox;
                
                aux->prox = l2->inicio;
                l1->qtd = l1->qtd + l2->qtd;
                l2->inicio=NULL;
                l2->qtd=0;
            }
        }

    }
}