#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int pilha[TAM];
int topo = 0;

int empty();
void push(int x);
int pop();
int stackpop();

int main()
{
    int opcao, numero;
    do
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 5 - Sair");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            push(numero);
            break;
        case 2:
            if (!empty())
            {
                numero = pop();
                printf("\n Numero que saiu : %d",numero);
            }
            else
            {
                printf("\n Pilha vazia");
            }

            break;
        case 3:
            if (!empty())
            {
                numero = stackpop();
                printf("\n Numero que esta para sair : %d",numero);
            }
            else
            {
                printf("\n Pilha vazia");
            }
            break;
        case 5:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);

    printf("\n");
    return 0;
}

int empty()
{
    if (topo == 0)
        return 1;
    else
        return 0;
}

void push(int x)
{
    if (topo == TAM)
        printf("\nPilha cheia");
    else
    {
        pilha[topo] = x;
        topo++;
    }
}

int pop()
{
    if (empty())
    {
        printf("\n Pilha vazia");
        return -1;
    }
    else
        return pilha[--topo];
}

int stackpop()
{
    if (empty())
        printf("\n Pilha vazia");
    else
        return pilha[topo - 1];
}