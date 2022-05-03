#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


void pares();
void impares();
void primos();
int primo(int x);


int main()
{

    omp_set_num_threads(3);
    #pragma omp parallel
    {
        int id;
        id = omp_get_thread_num();

        printf("\n Eu sou a thread: %d", id);

        #pragma omp sections
        {
            #pragma omp section
            {
                printf("\n EEu sou a thread: %d", id);
                pares();
            }
            #pragma omp section
            {
                printf("\n EEu sou a thread: %d", id);
                impares();
            }
            #pragma omp section
            {
                printf("\n EEu sou a thread: %d", id);
                primos();
            }
        }
    }

    printf("\n");
    return 0;
}

void pares()
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            printf("\n Par: %d", i);
    }
}

void impares()
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        if (i % 2 != 0)
            printf("\nImpar: %d", i);
    }
}

void primos()
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        if (primo(i))
            printf("\nPrimo: %d", i);
    }
}

int primo(int x)
{
    if (x == 0 || x == 1)
        return 0;

    int div;

    for (div = 2; div < x; div++)
    {
        if (x % div == 0)
            return 0;
    }

    return 1;
}