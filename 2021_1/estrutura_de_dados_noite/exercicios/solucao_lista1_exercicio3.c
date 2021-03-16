
// 3) Faça um programa que leia do usuário um número N inteiro positivo e solicite ao usuário N números para serem armazenados.
//     a primeira metade dos N números, deverá ser armazenada em uma lista ligada e a segunda metade dos N números deverá ser 
//     armazenado em uma segunda lista.

//     Mostre na tela quais valores são comuns entre as 2 listas ligadas.



#include <stdio.h>
#include <stdlib.h>

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
void elementos_em_comum(lista * l1, lista * l2);

lista * aloca_lista();
registro * aloca_registro();
void incluir_no_final(lista * l, int x);
void mostrar_lista(lista * l);
int busca_na_lista(lista *l , int x);


int main()
{
    lista * l1, *l2;
    l1 = aloca_lista();
    l2 = aloca_lista();
    int n,i,meio,numero;
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

    elementos_em_comum(l1,l2);

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

int busca_na_lista(lista *l , int x)
{
    if (l->inicio==NULL)
    {
        return 0;
    }

    registro * aux;

    aux = l->inicio;

    while(aux!=NULL)
    {
        if (aux->valor == x)
            return 1;
        else
            aux = aux->prox;
    }
    return 0;
}


void elementos_em_comum(lista * l1, lista * l2)
{
    if (l1->inicio == NULL || l2->inicio==NULL)
    {
        printf("\n Nao existem elementos em comum");
        return;
    }

    registro * aux;

    aux = l1->inicio;

    while(aux!=NULL)
    {
        if(busca_na_lista(l2,aux->valor))
        {
            printf("\n %d",aux->valor);
        }
        aux=aux->prox;
    }

}

int remover(lista *l, int x)
{
    if (l->inicio==NULL)
    {
        return 0;
    }

    registro * aux=NULL, *ant=NULL;

    aux=l->inicio;
    while(aux!=NULL)
    {   
        if (aux->valor == x)
        {
            if (ant==NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1;
        }
        ant = aux;
        aux = aux->prox;
    }

    return 0;

}