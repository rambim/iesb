#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int fila[200000];
int ultimo = 0;
int primeiro = 0;
int cheio = 0;

void push(int x);
int pop();
int main()
{

    double t1, t2;
    int x = 200000;
    int tam = x;
    int opcao, numero;

    t1 = omp_get_wtime();
    while (tam--)
    {
        push(tam);
    }

    tam = x;

    while (tam--)
    {
        pop();
    }
    t2 = omp_get_wtime();

    printf("\n Tempo gasto: %lf", t2 - t1);

    // do
    // {
    //     printf("\n 1- Incluir");
    //     printf("\n 2- Remover");
    //     printf("\n 5- Sair");
    //     printf("\n opcao: ");
    //     scanf("%d", &opcao);

    //     numero = 0;
    //     switch (opcao)
    //     {
    //     case 1:
    //         printf("\n Digite um numero: ");
    //         scanf("%d", &numero);
    //         push(numero);
    //         break;
    //     case 2:
    //         numero = pop();
    //         printf("\n Saindo: -> %d",numero);
    //         break;
    //     case 5:
    //         printf("\n saindo do programa");
    //         break;
    //     default:
    //         printf("\n opcao invalida");
    //         break;
    //     }
    // } while (opcao != 5);

    printf("\n");
    return 0;
}

void push(int x)
{
    if (primeiro == ultimo && cheio)
    {
        printf("\n Fila cheia");
        return;
    }
    else
    {
        fila[ultimo] = x;
        ultimo++;
        if (ultimo == 200000)
        {
            ultimo = 0;
        }
        if (ultimo == primeiro)
        {
            cheio = 1;
        }
    }
}

int pop()
{
    if (primeiro==ultimo && !cheio)
    {
        printf("\n Fila vazia");
        return 0;
    }
    else
    {
        int aux;
        aux = fila[primeiro];
        primeiro++;
        if (primeiro == 200000)
        {
            primeiro = 0;
        }
        if (primeiro == ultimo)
        {
            cheio=0;
        }
        return aux;
    }
}
