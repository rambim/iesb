#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codigo, qtd;

    double valor, total;

    scanf("%d %d", &codigo, &qtd);

    if (codigo == 1)
        valor = 4;
    if (codigo == 2)
        valor = 4.5;
    if (codigo == 3)
        valor = 5;
    if (codigo == 4)
        valor = 2;
    if (codigo == 5)
        valor = 1.5;

    total = qtd * valor;
    printf("Total: R$ %.2lf\n", total);
}