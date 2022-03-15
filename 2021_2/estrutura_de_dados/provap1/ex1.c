/* 

Implemente um programa que possua a função “primos_no_final”, essa função deve receber uma 
lista ligada simples e percorrê-la, caso encontre um número primo a função  deve 
move-lo para o final da lista. Ao fim da execução da função, todos os números primos
 da lista devem estar nas últimas posições da mesma. Na sua função principal leia N 
 números do usuário e utilizando  a função “primos_no_final”, mostre a lista dos números 
 digitados com os números primos no final da lista.



*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista_ligada
{
    struct registro * inicio;
}lista_ligada;

typedef struct registro
{
    int valor;
    struct registro * prox;
    int movido;
}registro;

int incluir_no_inicio(lista_ligada * l , int x);
void mostrar(lista_ligada * l);
registro * aloca_registro ();
lista_ligada * aloca_lista();
int primo(int x);
void primos_no_final(lista_ligada * l);
void primos_no_final2(lista_ligada * l);

int main()
{
    int n,i,valor;

    lista_ligada * l1;

    l1 = aloca_lista();

    printf("\n digite N: ");
    scanf("%d",&n);

    i = n;
    while(i--)
    {
        scanf("%d",&valor);
        incluir_no_inicio(l1,valor);
    }

    printf("\n Antes: ");
    mostrar(l1);

    primos_no_final2(l1);

    printf("\n Depois: ");
    mostrar(l1);

    printf("\n");
    return 0;
}

lista_ligada * aloca_lista()
{
    lista_ligada * novo;

    novo = (lista_ligada*)calloc(1,sizeof(lista_ligada));
    return novo;
}

registro * aloca_registro ()
{
    registro * novo;
    novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}

int incluir_no_inicio(lista_ligada * l , int x)
{
    if (l==NULL)
        return 0;

    registro * novo;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    return 1;
}

void mostrar(lista_ligada * l)
{
    registro * aux;

    if (l==NULL)
        return;

    if (l->inicio==NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    aux = l->inicio;

    while(aux!=NULL)
    {
        printf("\n %d",aux->valor);
        aux = aux->prox;


    }

}

void primos_no_final(lista_ligada * l)
{
    if (l==NULL)
        return;

    if (l->inicio==NULL)
        return;

    registro * aux=NULL, * ant=NULL, * aux2, * prox=NULL;

    aux = l->inicio;

    while(aux!=NULL)
    {
        prox = aux->prox;

        if (primo(aux->valor) && aux->movido==0)
        {
            aux2 = aux;
            while(aux2->prox!=NULL)
            {
                aux2 = aux2->prox;
            }

            if (ant==NULL)
                l->inicio = aux->prox;
            else
                ant->prox = aux->prox;

            aux2->prox = aux;
            aux->movido = 1;
            aux->prox=NULL;
        }
        else
        {
            ant = aux;
            printf("\n NAO ENTREI PARA valor %d",aux->valor);
        }
        aux = prox;
    }
}

void primos_no_final2(lista_ligada * l)
{
    if (l==NULL)
        return;

    if (l->inicio==NULL)
        return;

    registro * aux=NULL,*ant=NULL,*prox=NULL;

    aux = l->inicio;
    lista_ligada * lista_primos;

    lista_primos = aloca_lista();

    while(aux!=NULL)
    {
        prox = aux->prox;
        if (primo(aux->valor))
        {
            incluir_no_inicio(lista_primos,aux->valor);
            if (ant==NULL)
                l->inicio = aux->prox;
            else
                ant->prox = aux->prox;
            free(aux);
        }
        else
        {
            ant=aux;
        }
        aux = prox;;
    }


    printf("\n Mostrando lista original sem os primos: ");
    mostrar(l);

    printf("\n Mostrar lista dos primos: ");
    mostrar(lista_primos);

    //juntando a lista original da lista de primos
    ant->prox = lista_primos->inicio;

    free(lista_primos);
    
}

int primo(int x)
{
    if (x<2)
        return 0;

    int div;

    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }
    return 1;

}

