/*


Faça um programa que receba 2 notas do usuario, calcule a média aritmética dessas notas
e mostre na tela se o usuário está aprovado ou reprovado.

Reprovado : entre 0 - 5
Aprovado  : maior que 5 e menor igual a 10.




*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2, media;

    printf("\n Digite a n1: ");
    scanf("%f", &n1);
    printf("\n Digite a N2: ");
    scanf("%f", &n2);

    media = (n1 + n2) / 2.0;

    printf("\n Media = %f", media);

    if (media >= 0 && media < 5)
    {
        printf("\n Reprovado");
    }
    else
    {
        if (media >= 5 && media <= 10)
        {
            printf("\n Aprovado");
        }
    }
    printf("\n");
    return 0;
}