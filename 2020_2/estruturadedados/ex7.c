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

registro *aloca_registro();
lista *aloca_lista();
void incluir_na_lista(lista *l, int x);
void mostrar(lista * l);

int main()
{
    lista * lista_do_felippe;
    int numero=0;

    lista_do_felippe = aloca_lista();

    while(numero!=-1)
    {
        printf("\n Digite um numero para ser includo na lista: ");
        scanf("%d",&numero);
        incluir_na_lista(lista_do_felippe,numero);
    }

    mostrar(lista_do_felippe);   



    return 0;
}

lista *aloca_lista()
{
    lista *nova_lista;

    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;
    return nova_lista;
}

registro *aloca_registro()
{
    registro *novo_registro;
    novo_registro = (registro *)malloc(sizeof(registro));
    novo_registro->valor = 0;
    novo_registro->prox = NULL;
    return novo_registro;
}

void incluir_na_lista(lista *l, int x)
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

void mostrar(lista * l)
{
    registro * aux;

    if ( l->qtd==0)
    {
        printf("\n Lista vazia");
    }
    else
    {
        aux= l->inicio;
        while(aux!=NULL)
        {
            printf("\n%d",aux->valor);
            aux = aux->prox;
        }

    }
    
}
