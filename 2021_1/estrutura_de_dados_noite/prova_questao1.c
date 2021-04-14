// Implemente um programa que possua a função “primos_no_inicio”, essa função deve receber uma lista 
// ligada simples e percorrê-la, caso encontre um número primo a função  deve move-lo para o início da 
// lista. Ao fim da execução da função, todos os números primos da lista devem estar nas primeiras posições
//  da mesma. Na sua função principal leia N números do usuário e utilizando  a função “primos_no_inicio”, 
//  mostre a lista dos números digitados com os números primos na frente.


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
lista * aloca_lista();
registro * aloca_registro();
void incluir_no_inicio ( lista * l, int x);
void mostrar(lista * l);
int primo(int x);
void remover_perfeitos (lista * l);

int main()
{
    lista * l1;
    l1 = aloca_lista();
    int n,i,numero;
    printf("\n Digite quantos numeros deseja inserir: ");
    scanf("%d",&n);

    printf("\n Digite os numeros: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&numero);
        incluir_no_inicio(l1,numero);
    }


    mostrar(l1);
    remover_perfeitos(l1);
    printf("\n Mostrando com primos no inicio: ");
    mostrar(l1);
    printf("\n");
    return 0;
}

lista * aloca_lista()
{
    lista * novo;
    novo =(lista*)calloc(1,sizeof(lista));
    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo =(registro*)calloc(1,sizeof(registro));
    return novo;
}

void incluir_no_inicio ( lista * l, int x)
{
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
    l->qtd++;
    
}

void mostrar(lista * l)
{
    registro * aux;
    aux = l->inicio;
    while(aux!=NULL)
    {
        printf("\n %d",aux->valor);
        aux = aux->prox;
    }
}

void remover_perfeitos (lista * l)
{
    registro * aux,*ant=NULL,*removido=NULL;

    if (l->inicio==NULL)
    {
        printf("\n lista vazia");
        return;
    }

    aux = l->inicio;
    while(aux!=NULL)
    {
        if (primo(aux->valor))
        {
            if (ant==NULL)
                l->inicio = aux->prox;
            else
                ant->prox = aux->prox;

            removido = aux;
            incluir_no_inicio(l,removido->valor);
            aux = aux->prox;
            free(removido);
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }
}

int primo(int x)
{
    if ((x==1)|| (x==0))
        return 0;
    int div;
    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }
    return 1;
}
