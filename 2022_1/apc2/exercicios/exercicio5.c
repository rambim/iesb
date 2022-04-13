#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numero;

    // numero = maior_numero(4,5);

    maior_numero2(4,5,&numero);

    printf("\n NUmero : %d",numero);

    return 0;
}

int maior_numero(int a, int b)
{
    if ( a>b)
        return a;
    else
        return b;
}

void maior_numero2(int a, int b, int * numero)
{
    if (a>b)
        *numero = a;
    else
        *numero = b;
}

