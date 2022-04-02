#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

long long int fibo1(long long int n);
long long int fibo2(long long int n);
long long int main()
{
    long long int i;

    double t1, t2;

    
    for (i = 1; i < 100; i++)
    {
        
        printf("\n\n Termo : %lld",i);

        t1 = omp_get_wtime();
        printf("\nR: %lld", fibo1(i));
        t2 = omp_get_wtime();
        printf("\n Tempo Recursivo: %lf",t2-t1);


        t1 = omp_get_wtime();
        printf("\nR: %lld", fibo2(i));
        t2 = omp_get_wtime();
        printf("\n Tempo iterativo: %lf",t2-t1);
    }
}

long long int fibo1(long long int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return (fibo1(n - 1)) + (fibo1(n - 2));
}

long long int fibo2(long long int n)
{
    long long int a = 0, b = 1, c;
    long long int i = 2;

    if (n == 1)
        return a;
    else
    {
        if (n == 2)
            return b;
        else
        {
            while (i < n)
            {
                c = a + b;
                a = b;
                b = c;
                i++;
            }
            return c;
        }
    }
}