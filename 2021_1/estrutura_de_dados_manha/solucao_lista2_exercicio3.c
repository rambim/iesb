// 3) Faça um programa que leia do usuário um número N inteiro positivo e solicite ao usuário N números para serem armazenados.
//     a primeira metade dos N números, deverá ser armazenada em uma lista ligada e a segunda metade dos N números deverá ser 
//     armazenado em uma segunda lista.

//     Mostre na tela quais valores são comuns entre as 2 listas ligadas.

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
int buscar_na_lista(lista * l, int x);
void mostrar_numeros_comuns(lista * l1, lista * l2);

void mostrar_lista(lista *l);

int main()
{

    int n, meio,i,numero;
    lista * l1, *l2;

    l1 = aloca_lista();
    l2 = aloca_lista();
    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    meio = n/2;

    for(i=0;i<n;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&numero);
        if (i<meio)
            incluir_no_final(l1,numero);
        else
            incluir_no_final(l2,numero);
    }

    mostrar_numeros_comuns(l1,l2);

    printf("\n");
    return 0;
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


int buscar_na_lista(lista * l, int x)
{
    if (l->inicio==NULL)
    {
        return 0;
    }

    registro * aux;
    aux = l->inicio;

    while(aux!=NULL)
    {
        if (aux->valor==x)
        {
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}


void mostrar_numeros_comuns(lista * l1, lista * l2)
{
    registro * aux;
    if (l1->inicio==NULL || l2->inicio==NULL)
    {
        printf("\n Nao existem numeros em comum ");
        return ;
    }

    aux = l1->inicio;

    while(aux!=NULL)
    {
        if (buscar_na_lista(l2,aux->valor))
        {
            printf("\n Numero em comum nas listas: %d",aux->valor);
        }
        aux=aux->prox;
    }
}