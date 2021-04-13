// Implemente um programa que possua uma função "remove_perfeitos". Essa função deve receber 
// por parâmetro uma lista ligada e remover todos números perfeitos que estão dentro da lista.
//  Na sua função principal leia do usuário N números e utilizando a função criada remova os 
//  números perfeito da lista de N números.



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
int perfeito(int x);
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
    printf("\n Mostrando sem os numeros perfeitos: ");
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
        if (perfeito(aux->valor))
        {
            if (ant==NULL)
                l->inicio = aux->prox;
            else
                ant->prox = aux->prox;

            removido = aux;
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

int perfeito(int x)
{
    int som=0,i;
    for(i=1;i<x;i++)
    {
        if (x%i==0)
        {
            som = som + i;
        }
    }
    if (som==i) 
        return 1;
    else
        return 0;
}
