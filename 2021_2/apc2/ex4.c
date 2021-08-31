#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota;

    printf("\nDigite sua nota: ");
    scanf("%f",&nota);

    if (nota<0 || nota > 10)
    {
        printf("\n Nota invalida");
    }

    if (nota >=0 && nota <5)
    {
        printf("\n Reprovado");
    }

    if (nota >=5 && nota<=10)
    {
        printf("\n Aprovado");
    }
}