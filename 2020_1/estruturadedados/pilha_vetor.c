#include <stdio.h>
#include <stdlib.h>
#define tam 10

int qtd = 0;
int vet[tam];

int push(int x);
int pop();
int stackpop();
int empty();
int full();
void mostra();
void menu();

int main()
{
    menu();
    return 0;
}

int push(int x)
{
    if (full())
    {
        return 0;
    }
    else
    {
        vet[qtd] = x;
        qtd++;
        return 1;
    }
}

int pop()
{
    int x;

    if (empty())
    {
        return -1;
    }
    else
    {
        qtd--;
        x = vet[qtd];
        vet[qtd] = -1;
        return x;
    }
}

int stackpop()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return vet[qtd - 1];
    }
}

int empty()
{
    if (qtd == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full()
{
    if (qtd == tam)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
void inicializa()
{
    int i;

    for(i=0;i<tam;i++)
    {
        vet[i] = -1;
    }
}
*/

void mostra()
{
    int i;
    printf("\n Pilha: ")
    for (i = tam-1; i >= 0; i--)
    {
        printf("\n%d", vet[i]);
    }
    printf("\n");
}

void menu()
{
    int opcao;
    int numero, retorno;

    do
    {
        mostra();
        printf("\n1 - push");
        printf("\n2 - pop");
        printf("\n3 - stackpop");
        printf("\n4 - empty");
        printf("\n5 - full");
        printf("\n6 - sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um valor: ");
            scanf("%d", &numero);

            if (push(numero))
            {
                printf("\n Numero incluido com sucesso");
            }
            else
            {
                printf("\n Pilha cheia");
            }

            break;
        case 2:

            if (empty())
            {
                printf("\n Pilha vazia");
            }
            else
            {
                retorno = pop();
                printf("\n Pop de  %d", retorno);
            }
            break;
        case 3:
            if (empty())
            {
                printf("\n pilha vazia");
            }
            else
            {
                retorno = stackpop();
                printf("\n Numero no topo da pilha: %d", retorno);
            }

            break;
        case 4:
            if (empty())
            {
                printf("\n pilha esta vazia");
            }
            else
            {
                printf("\n Pilha nao esta vazia");
            }

            break;
        case 5:
            if (full())
            {
                printf("pilha cheia");
            }
            else
            {
                printf("pilha nao esta cheia");
            }

            break;
        case 6:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n Opcao invalida");
        }
    } while (opcao != 6);
}