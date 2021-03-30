#include <stdio.h>
#include <stdlib.h>

int empty();
int size_da_pilha();
int push(int x);
int pop();
int stackpop();

int pilha[10];
int topo = 0;

int main()
{
    int opcao, numero;

    do
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Stackpop");
        printf("\n 4 - Empty");
        printf("\n 5 - Sair");
        scanf("%d", &opcao);

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
                printf("\n numero que saiu da pilha : %d", numero);
            }
            else
            {
                printf("\n pilha vazia");
            }
            break;
        case 3:
            if (!empty())
            {
                numero = stackpop();
                printf("\n numero que esta no topo da pilha: %d", numero);
            }
            else
            {
                printf("\n pilha vazia");
            }
            break;
        case 4:
            if (empty())
                printf("\n Pilha vazia");
            else
                printf("\n pilha nao esta vazia");
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao !=5);

    return 0;
}

int empty()
{
    if (topo == 0)
        return 1;
    else
        return 0;
}

int size_da_pilha()
{
    return topo;
}

int push(int x)
{
    if (topo == 10)
        printf("\n Pilha cheia");
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
        printf("pilha vazia");
        return -1;
    }
    else
    {
        topo--;
        return pilha[topo];
    }
}

int stackpop()
{
    if (empty())
    {
        printf("\n Pilha vazia");
        return -1;
    }
    else
    {
        return pilha[topo - 1];
    }
}
