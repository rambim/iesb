#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int pilha[TAM];
int topo=0;


void push(int x);
int pop();

int main()
{
    push(1);
    push(2);
    push(3);

    printf("\n Saiu da pilha %d",pop());
    printf("\n Saiu da pilha %d",pop());
    printf("\n Saiu da pilha %d",pop());
    
    return 0;
}

void push(int x)
{
    if (topo >= TAM)
    {
        printf("\n Pilha cheia");
    }
    else{
        pilha[topo++] = x;
    }
}

int pop()
{
    if (topo==0)
    {
        printf("\n Pilha vazia");
    }
    else{
        return pilha[--topo];
    }
}

int stackpop()
{
    if (topo==0)
    {
        printf("\n Pilha vazia");
    }
    else{
        return pilha[topo-1];
    }
}

int empty()
{
    return topo == 1 ? 1 : 0;
}