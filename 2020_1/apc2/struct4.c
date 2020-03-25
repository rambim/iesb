#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int valor1;
    int valor2;
} aluno;

int dobrar(aluno a);

int main()
{
    aluno a;
    int x;
    a.valor1 = 2;
    a.valor2 = 3;
    x = dobrar(a);

    printf("\n VAlor de x = %d", x);

    printf("\n Fora da funcao: ");
    printf("\n Valor 1  = %d valor 2  = %d", a.valor1, a.valor2);

    return 0;
}

int dobrar(aluno a)
{
    a.valor1 = a.valor1 * 2;
    a.valor2 = a.valor2 * 2;

    printf("\n Dentro da funcao: ");
    printf("\n Valor 1  = %d valor 2  = %d", a.valor1, a.valor2);
    printf("\n saindo da funcao ");
    return 33;
}