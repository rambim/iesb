#include <stdio.h>
#include <stdlib.h>
#define tam 10

int qtd = 0;
int qtd1=0;
int qtd2=0;
int fim= tam-1 ;
int vet[tam];

int push1(int x);
int push2(int x);
int pop1();
int pop2();
int stackpop1();
int stackpop2();
int empty1();
int empty2();
int full();
void mostra();
void menu();

int main()
{
    menu();
    return 0;
}

int push2(int x)
{
    if (full())
    {
        return 0;
    }
    else
    {

        vet[fim] = x;
        fim--;
        qtd2++;

        return 1;
    }
}
int push1(int x)
{
    if (full())
    {
        return 0;
    }
    else
    {
        vet[qtd] = x;
        qtd++;
        qtd1++;
        return 1;
    }
}

int pop1()
{
    int x;

    if (empty1())
    {
        return -1;
    }
    else
    {
        qtd--;
        x = vet[qtd];
        vet[qtd] = -1;

 qtd1--;
        return x;

    }
}
int pop2()
{
    int x;

    if (empty2())
    {
        return -1;
    }
    else
    {
              fim++;
        x = vet[fim];
        vet[fim] = -1;

qtd2--;
        return x;

    }
}

int stackpop1()
{
    if (empty1())
    {
        return -1;
    }
    else
    {
        return vet[qtd -1 ];
    }
}

int stackpop2()
{
    if (empty2())
    {
        return -1;
    }
    else
    {
        return vet[fim + 1 ];
    }
}

int empty1()
{
    if (qtd1 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int empty2()
{
    if (qtd2 == 0)
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
    if (qtd1+qtd2 == tam)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void mostra()
{
    int i;
    printf("\n Pilha: ");
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
        printf("\n1 - push 1");
        printf("\n2 - push 2");
        printf("\n3 - pop1");
        printf("\n4 - pop2");
        printf("\n5 - empty1");
        printf("\n6 - empty2");
        printf("\n7 - stackpop1");
        printf("\n8 - stackpop2");
        printf("\n9 - full");
        printf("\n0 - sair");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um valor para pilha 1: ");
            scanf("%d", &numero);

            if (push1(numero))
            {
                printf("\n Numero incluido com sucesso");
            }
            else
            {
                printf("\n Pilha cheia");
            }

            break;
        case 2:
            printf("\n Digite um valor para pilha 2: ");
            scanf("%d", &numero);

            if (push2(numero))
            {
                printf("\n Numero incluido com sucesso");
            }
            else
            {
                printf("\n Pilha cheia");
            }

            break;
        case 3:

            if (empty1())
            {
                printf("\n Pilha vazia");
            }
            else
            {
                retorno = pop1();
                printf("\n Pop de  %d", retorno);
            }
            break;
          case 4:

            if (empty2())
            {
                printf("\n Pilha vazia");
            }
            else
            {
                retorno = pop2();
                printf("\n Pop de  %d", retorno);
            }
            break;
        case 5:
            if (empty1())
            {
                printf("\n pilha esta vazia");
            }
            else
            {
                printf("\n Pilha nao esta vazia");
            }

            break;
         case 6:
            if (empty2())
            {
                printf("\n pilha esta vazia");
            }
            else
            {
                printf("\n Pilha nao esta vazia");
            }

            break;

          case 7:
            if (empty1())
            {
                printf("\n pilha vazia");
            }
            else
            {
                retorno = stackpop1();
                printf("\n Numero no topo da pilha: %d", retorno);
            }
            break;
          case 8:
            if (empty2())
            {
                printf("\n pilha vazia");
            }
            else
            {
                retorno = stackpop2();
                printf("\n Numero no topo da pilha: %d", retorno);
            }
                break;
        case 9:
            if (full())
            {
                printf("pilha cheia");
            }
            else
            {
                printf("pilha nao esta cheia");
            }

            break;
        case 10:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n Opcao invalida");
        }
    } while (opcao != 10);
}

