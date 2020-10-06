#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "omp.h"

long int fibo_recursivo(long int n);
long int fibo_iterativo(long int n);
long int fibo_matematico(long int n);

int main(int argc, char *argv[])
{
    long int x, retorno;

    long int i;
    long int j;

    double t1, t2;

    double sum1 = 0, sum2 = 0, sum3 = 0;
    double media1, media2, media3;

    x = atoi(argv[1]);

    for (i = 0; i < 5; i++)
    {
        printf("\n %ld Execucao: \n", i + 1);
        if (x >= 46)
        {
            printf("\n Recursivo * 1    : %ld zimo tempo: acima de 10 seg", x);
        }
        else
        {
            t1 = omp_get_wtime();
            retorno = fibo_recursivo(x);
            t2 = omp_get_wtime();
            printf("\n Recursivo * 1    : %ld zimo termo: %ld tempo: %lf", x, retorno, t2 - t1);
            sum1 = sum1 + (t2 - t1);
            
        }

        t1 = omp_get_wtime();
        for (j = 0; j < 10000000; j++)
        {
            retorno = fibo_iterativo(x);
        }
        t2 = omp_get_wtime();
        printf("\n Iterativo * 10^7 : %ld zimo termo: %ld tempo: %lf", x, retorno, t2 - t1);
        sum2 = sum2 + (t2 - t1);

        t1 = omp_get_wtime();
        for (j = 1; j < 10000000; j++)
        {
            retorno = fibo_matematico(x);
        }
        t2 = omp_get_wtime();
        printf("\n Matematico * 10^7: %ld zimo termo: %ld tempo: %lf", x, retorno, t2 - t1);
        sum3 = sum3 + (t2 - t1);

        printf("\n");
    }

    media1 = sum1 / 5;
    media2 = sum2 / 5;
    media3 = sum3 / 5;

    if (x>45)
    {
        printf("\n Tempo medio Recursivo * 1      : maior que 10s");    
    }
    else
    {
    printf("\n Tempo medio Recursivo * 1      : %lf", media1);
        
    }
    
    printf("\n Tempo medio Iterativo  * 10 ^ 7: %lf", media2);
    printf("\n Tempo medio matematico * 10 ^ 7: %lf", media3);

    printf("\n ");
    return 0;
}

long int fibo_recursivo(long int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 1;
    }

    return fibo_recursivo(n - 1) + fibo_recursivo(n - 2);
}

long int fibo_iterativo(long int n)
{
    long int ultimo = 1;
    long int penultimo = 1;
    long int atual;
    long int i;

    if (n == 1)
    {
        return penultimo;
    }
    else
    {
        if (n == 2)
        {
            return ultimo;
        }
        else
        {
            for (i = 2; i < n; i++)
            {
                atual = ultimo + penultimo;
                penultimo = ultimo;
                ultimo = atual;
            }
        }
    }

    return atual;
}

long int fibo_matematico(long int n)
{
    double x;
    double n1, n2, d1, d2, f1, f2, p1, p2;

    n1 = 1 + sqrt(5);
    d1 = 2;
    f1 = n1 / d1;

    n2 = 1 - sqrt(5);
    d2 = 2;
    f2 = n2 / d2;

    p1 = pow(f1, n);
    p2 = pow(f2, n);

    x = (1 / sqrt(5) * (p1 - p2));

    return (long int)x;
}
