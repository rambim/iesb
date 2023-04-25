#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    struct elemento * topo;
    
}pilha;

typedef struct elemento
{
    int valor;
    struct elemento * prox;
}elemento;

void push(pilha * p, int x);
void pop(pilha * p);
void min(pilha * p);

int main()
{

    char texto[50];
    char numero_char[50];
    int numero_int;
    pilha p;
    p.topo=NULL;
    int n,valor;
    // pop(&p);
    scanf("%d",&n);

    while(n--)
    {
        scanf("%s",texto);

        if (strcmp(texto,"PUSH")==0)
        {
            scanf("%d",&numero_int);
            push(&p,numero_int);
            
        }
        else
        {
            if (strcmp(texto,"POP")==0)
            {
                pop(&p);
            }
            else
            {
               
                min(&p);

            }
        }
    }


    
    
    return 0;
    
}

void push(pilha * p, int x)
{
    elemento * novo;
    novo =(elemento*)malloc(sizeof(elemento));
    novo->valor = x;
    novo->prox=NULL;

    if (p->topo == NULL)
    {
        p->topo = novo;
    }
    else
    {

        novo->prox = p->topo;
        p->topo = novo;
    }

}

void pop(pilha * p)
{
    if (p->topo==NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        p->topo = p->topo->prox;
    }
}

void min(pilha * p)
{
    int menor = 11000000;
    if (p->topo==NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        elemento * aux;
        aux=p->topo;
        do
        {
            if (aux->valor < menor)
            {
                menor = aux->valor;
            }
            aux = aux->prox;
        } while (aux!=NULL);
        printf("%d\n",menor);
    }
}