#include <stdio.h>
#include <stdlib.h>

void mostrar_fila();
void inicializar_vetor();
int pop_fila();
void push_fila(int numero);

int fila[5];
int inicio = 0;
int fim = 0;

int main()
{
    int opcao;
    int numero;
        inicializar_vetor();

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

void mostrar_fila()
{
    int i;
    printf("\n Fila: ");
    for (i = 0; i < 5; i++)
    {
        printf(" %d", fila[i]);
    }
}

void inicializar_vetor()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        fila[i] = -1;
    }
}

void push_fila(int numero)
{
    if (inicio == fim && fila[fim] != -1)
    {
        printf("\n Fila cheia");
    }
    else
    {
        fila[fim] = numero;
        fim++;
        if (fim >= 5)
        {
            fim = 0;
        }
    }
}

int pop_fila()
{

    int retorno;
    if (inicio == fim && fila[inicio] == -1)
    {
        printf("\n Fila vazia");
        return -1;
    }
    else
    {
        retorno = fila[inicio];
        fila[inicio] = -1;
        inicio++;
        if (inicio >= 5)
        {
            inicio = 0;
        }
    }
    return retorno;
}