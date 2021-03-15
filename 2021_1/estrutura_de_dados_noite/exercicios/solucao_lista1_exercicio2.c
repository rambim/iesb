#include <stdio.h>
#include <stdlib.h>


// 2) Faça um programa que leia do usuário 10 números inteiros e armazene os números pares em uma lista ligada
// e os números ímpares em uma segunda lista ligada. Mostre o conteúdo das 2 listas;

typedef struct lista
{
    int qtd;
    struct registro * inicio;
}lista;

typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;


lista * aloca_lista();
registro * aloca_registro();
void incluir_no_final(lista * l, int x);
void mostrar_lista(lista * l);


int main()
{
    lista * pares, *impares;
    int i,numero;

    pares = aloca_lista();
    impares = aloca_lista();

    for(i=0;i<10;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&numero);

        if (numero%2==0)
            incluir_no_final(pares,numero);
        else
            incluir_no_final(impares,numero);

    }

    printf("\n Mostrando lista dos pares: ");
    mostrar_lista(pares);
    printf("\n Mostrando lista dos impares: ");
    mostrar_lista(impares);

    printf("\n");
    return 0;
}

lista * aloca_lista()
{
    lista * novo;
    novo =(lista*)malloc(sizeof(lista));
    novo->qtd=0;
    novo->inicio=NULL;
    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo = (registro*)malloc(sizeof(registro));
    novo->valor=0;
    novo->prox=NULL;
    return novo;
}

void incluir_no_final(lista * l, int x)
{
    registro * novo,*aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while(aux->prox!=NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    l->qtd++;
}


void mostrar_lista(lista * l)
{
    registro * aux;

    if (l->inicio==NULL)
    {
        printf("\n lista vazia");
    }  
    else
    {
        aux = l->inicio;

        while(aux!=NULL)
        {
            printf("\n Valor: %d",aux->valor);
            aux = aux->prox;
        }
    }
}