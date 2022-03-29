#include <stdio.h>
#include <stdlib.h>

int pop_fila();
void push_fila(int numero);

int fila[5];
int fim = 0;

int main()
{
    int opcao;
    int numero;

    do
    {
        printf("\n 1 - incluir na fila");
        printf("\n 2 - remover da fila");
        printf("\n 3 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero para ser incluido na fila:");
            scanf("%d", &numero);
            push_fila(numero);
            break;
        case 2:
            numero = pop_fila();
            if (numero!=-1)
            {
                printf("\n numero que saiu da fila %d", numero);
            }
            break;
        case 3:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 3);
    return 0;
}

void push_fila(int numero)
{
    if (fim >= 5)
    {
        printf("\n Fila cheia, teste novamente mais tarde");
    }
    else
    {
        fila[fim] = numero;
        fim++;
    }
}

int pop_fila()
{
    int retorno;
    int i;

    if (fim == 0)
    {
        printf("\n Fila vazia");
        return -1;
    }
    else
    {
        retorno = fila[0];

        for (i = 0; i < fim - 1; i++)
        {
            fila[i] = fila[i + 1];
        }
        fim--;

        return retorno;
    }
}