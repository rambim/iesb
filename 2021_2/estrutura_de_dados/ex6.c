#include <stdio.h>
#include <stdlib.h>

int pilha[5] = {0};
int topo = 0;


void push(int x);
int pop();
int stackpop();
int empty();
int size();

int main()
{
    int opcao, numero, retorno;

    do
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Size\n Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero: ");
            scanf("%d",&numero);
            push(numero);
            break;
        case 2:
            numero = pop();
            printf("\n Numero que saiu -> %d",numero);
            break;
        case 3:
            numero = stackpop();
            printf("\n Numero que esta no topo da pilha -> %d",numero);
            break;
        case 4:
            if (empty())
                printf("\n Pilha vazia");
            else
                printf("\n Pilha contem elementos");
            break;
        case 5:
            printf("\n Tamanho da pilha: %d",size());
            break;
        }

    } while (opcao != 10);

    printf("\n");
    return 0;
}

void push(int x)
{
    if (topo == 5)
    {
        printf("\n Pilha cheia, nao e possivel inserir elementos");
    }
    else
    {
        pilha[topo] = x;
        topo++;
    }
}

int pop()
{
    int retorno = 0;
    if (topo == 0)
    {
        printf("\n Pilha vazia, nao e possivel remover elementos");
    }
    else
    {
        topo--;
        retorno = pilha[topo];
        pilha[topo] = 0;
        return retorno;
    }
    return 0;
}

int stackpop()
{
    return pilha[topo - 1];
}

int empty()
{
    if (topo == 0)
        return 1;
    else
        return 0;
}

int size()
{
    return topo;
}