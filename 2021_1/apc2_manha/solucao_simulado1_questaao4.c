// Faça um procedimento que recebe 3 valores inteiros por parâmetro e
// retorna-os ordenados em ordem crescente.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int n1, n2, n3;
} lista;

lista ordenar_numeros(int n1, int n2, int n3);

int main()
{
    lista l;

    l = ordenar_numeros(3, 2, 1);

    printf("\n%d %d %d", l.n1, l.n2, l.n3);
    return 0;
}

lista ordenar_numeros(int n1, int n2, int n3)
{
    lista l;
    /*
    1,2,3
    1,3,2
    2,1,3
    2,3,1
    3,1,2
    3,2,1
    */

    if (n1 <= n2 && n2 <= n3)
    {
        l.n1 = n1;
        l.n2 = n2;
        l.n3 = n3;
    }
    else
    {
        if (n1 <= n3 && n3 <= n2)
        {
            l.n1 = n1;
            l.n2 = n3;
            l.n3 = n2;
        }
        else
        {
            if (n2 <= n1 && n1 <= n3)
            {
                l.n1 = n2;
                l.n2 = n1;
                l.n3 = n3;
            }
            else
            {
                if (n2 <= n3 && n3 <= n1)
                {
                    l.n1 = n2;
                    l.n2 = n3;
                    l.n3 = n1;
                }
                else
                {
                    if (n3 <= n1 && n1 <= n2)
                    {
                        l.n1 = n3;
                        l.n2 = n1;
                        l.n3 = n2;
                    }
                    else
                    {
                        l.n1 = n3;
                        l.n2 = n2;
                        l.n3 = n1;
                    }
                }
            }
        }
    }
    return l;
}