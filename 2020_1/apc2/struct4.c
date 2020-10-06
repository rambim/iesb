#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int valor1;
    int valor2;
} aluno;

void dobrar1(aluno a);
void dobrar2(aluno *a);

int main()
{
    aluno a;

    a.valor1 = 2;
    a.valor2 = 3;

    dobrar1(a);
    printf("\n");
    printf("\n Fora da funcao: depois de dobrar 1");
    printf("\n Valor 1  = %d valor 2  = %d", a.valor1, a.valor2);

    printf("\n");
    dobrar2(&a);
    printf("\n Fora da funcao: depois de dobrar ");
    printf("\n Valor 1  = %d valor 2  = %d", a.valor1, a.valor2);
    printf("\n");


    return 0;
}

void dobrar1(aluno a)
{
    a.valor1 = a.valor1 * 2;
    a.valor2 = a.valor2 * 2;

    printf("\n Dentro da funcao: ");
    printf("\n Valor 1  = %d valor 2  = %d", a.valor1, a.valor2);
    printf("\n saindo da funcao ");
}

void dobrar2(aluno *a)
{
    // (*a).valor1 = (*a).valor1 * 2;
    // (*a).valor2 = (*a).valor2 * 2;
        a->valor1 = a->valor1 *2;
        a->valor2 = a->valor2 *2;
}
