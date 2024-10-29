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

void mostrar(lista * l, int * primos, int qtd_primos);
void inserir(lista * l, int x);
int primo(int x);

void inserir(lista * l, int x)
{
    registro * novo;
    registro * aux;

    novo = (registro*)calloc(1,sizeof(registro));
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
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    l->qtd++;
}

void mostrar(lista * l, int * primos, int qtd_primos)
{
    registro * aux;
    int i;
    int passos=0;

    if (l->inicio==NULL)
    {
        printf("\n vazio");
        return;
    }
    else
    {
        for(i=0;i<qtd_primos;i++)
        {
            passos=0;

            while(passos<primos[i])
            {
                
            }

            if (i==0)
                aux = l->inicio;


        }



    }
}


int main()
{

    int  * primos;
    int i=0;
    int qtd_primos=0;
    int n;
    lista * l;
    l = (lista*)calloc(1,sizeof(lista));
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        inserir(l,i);
    }

    // mostrar(l,n);

    primos = (int*)calloc(n-1,sizeof(int));

    i=0;
    while(qtd_primos<n-1)
    {
        if (primo(i))
        {
            primos[qtd_primos] = i;
            qtd_primos++;
        }
        i++;
    }

    printf("Vetor de primos: \n");
    for(i=0;i<qtd_primos;i++)
    {
        printf("%d\n",primos[i]);
    }
    return 0;
}


int primo(int x)
{
    if (x==1 || x==0)
        return 0;
    int divisor;

    for(divisor=2;divisor<x;divisor++)
    {
        if (x%divisor ==0)
            return 0;
    }

    return 1;


}