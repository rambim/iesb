/*

Escreva uma função potencia(base, expoente) que, quando chamada,
retorna baseexpoente . Por exemplo, potencia(3, 4) deve retornar 81. Assuma
que expoente é um inteiro maior ou igual a 1

*/


#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente);

int main()
{
    int resultado;

    resultado = potencia(3,4);

    printf("\n resultado : %d",resultado);
    printf("\n");
    return 0;
}

int potencia(int base, int expoente)
{

    int resultado;
    int i;
    resultado = 1;
    for(i=0;i<expoente;i++)
    {
        resultado = resultado * base;
    }

    return resultado;
}