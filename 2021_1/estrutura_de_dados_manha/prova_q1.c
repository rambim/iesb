// Implemente um programa que possua a função “primos_no_inicio”, essa função deve receber uma lista 
// ligada simples e percorrê-la, caso encontre um número primo a função  deve move-lo para o início da 
// lista. Ao fim da execução da função, todos os números primos da lista devem estar nas primeiras posições 
// da mesma. Na sua função principal leia N números do usuário e utilizando  a função “primos_no_inicio”, 
// mostre a lista dos números digitados com os números primos na frente.


#include <stdio.h>
#include <stdlib.h>



typedef struct registro
{
    int valor;
    struct registro * prox;
}registro;

typedef struct lista
{
    int qtd;
    struct registro * inicio;
}lista;

void mostrar ( lista * l);
lista * aloca_lista();
registro * aloca_registro();
void incluir_no_inicio(lista *l, int x);
void mostrar ( lista * l);
int primo(int x);
void primos_no_inicio(lista *l);



int main()
{
    lista * l ;
    l = aloca_lista();
    
    incluir_no_inicio(l,2);
    incluir_no_inicio(l,1);
    incluir_no_inicio(l,3);
    incluir_no_inicio(l,4);
    incluir_no_inicio(l,5);
    incluir_no_inicio(l,6);
    incluir_no_inicio(l,7);
    incluir_no_inicio(l,8);
    incluir_no_inicio(l,9);
    incluir_no_inicio(l,10);
    mostrar(l);
    primos_no_inicio(l);
    printf("\n Primos na frente");
    mostrar(l);
    printf("\n");
    return 0;
}

lista * aloca_lista()
{
    lista * novo;
    novo = (lista*)calloc(1,sizeof(lista));
    return novo;
}

registro * aloca_registro()
{
    registro * novo;
    novo = (registro*)calloc(1,sizeof(registro));
    return novo;
}

void incluir_no_inicio(lista *l, int x)
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

void mostrar ( lista * l)
{
    if (l->inicio==NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro * aux;
        aux = l->inicio;
        while(aux!=NULL)
        {
            printf("\n %d",aux->valor);
            aux = aux->prox;
        }
    }
}

void primos_no_inicio(lista *l)
{
    if (l->inicio==NULL)
    {
        printf("\n Lista vazia");
        return;
    }
    else
    {
        registro * aux=NULL,*ant=NULL,*removido=NULL;
        int p;

        aux = l->inicio;

        while(aux!=NULL)
        {
            if (primo(aux->valor))
            {
                p = aux->valor;

                if (ant==NULL)
                {
                    l->inicio = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                removido = aux;
                aux=aux->prox;
                free(removido);
                l->qtd--;
                incluir_no_inicio(l,p);

            }
            else
            {
                ant = aux;
                aux=aux->prox;
            }
        }
    }
}

int primo(int x)
{
    if ((x==0) || (x==1))
        return 0;
    
    int div;

    for(div=2;div<x;div++)
    {
        if (x%div==0)
            return 0;
    }
    return 1;
}


