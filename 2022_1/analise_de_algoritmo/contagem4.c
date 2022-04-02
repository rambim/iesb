#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double raiz_exata(double numero);

int main()
{
    double squareRoot;   // 0
    double vet[] = {100, 121, 144, 169}; // 1
    int i;

    for (i = 0; i < 4; i++) // 1 + tam1+ 1 + tam1 O (n)
    {
        squareRoot = raiz_exata(vet[i]); // (1 + NUMERO + (NUMERO - 1) +(1 * (NUMERO-1)))
        printf("\n %lf", squareRoot);
    }


    // O(n) * O(m) ~  o 

    // 1 + 4+ 1 + 4
    //(1 + 100 + (100 - 1) +(1 * (100-1)))
    //(1 + 121 + (121 - 1) +(1 * (121-1)))
    //(1 + 144 + (144 - 1) +(1 * (144-1)))
    //(1 + 169 + (169 - 1) +(1 * (169-1)))


    printf("\n");
    return 0;
}

double raiz_exata(double numero)
{

    o(m);
    int i;
    for (i = 1; i < numero; i++) // 1 + NUMERO + (NUMERO - 1)
    {
        if (numero / i == i) // (1 * (NUMERO-1))
            return i;
    }

    return 0;
    // Pior caso: 1 + NUMERO + (NUMERO - 1) +(1 * (NUMERO-1))
    // melhor caso: 1 + 1  = 2;
}