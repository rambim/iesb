

#include <stdio.h>
#include <stdlib.h>

int pilha[5];
int topo1=0;
int topo2=4;

int main()
{
    printf("\n");
    return 0;
}


void push_p1(int x)
{
    if (topo1<=topo2)
    {
        pilha[topo1] = x;
        topo1++;
    }
    else
    {
        printf("\n Pilha cheia");
    }
}
void push_p2(int x)
{
    if (topo2>=topo1)
    {
        pilha[topo2] = x;
        topo2--;
    }
    else
    {
        printf("\n Pilha cheia");
    }
}

int pop_p1()
{
    int retorno;
    if (topo1>0)
    {
        retorno = pilha[topo1-1];
        topo1--;
        return retorno;
    }
    else
    {
        printf("\n Pilha vazia");
    }
}

int pop_p2()
{
    int retorno;
    if (topo2<4)
    {
        retorno = pilha[topo2+1];
        topo2++;
        return retorno;
    }
    else
    {
        printf("\n Pilha vazia");
    }
}
