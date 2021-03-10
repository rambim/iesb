//2 - Faça um programa que receba do usuário uma temperatura em graus Celsius e transforme em Firenhaint


#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c,f;
    printf("\n Digite uma temperatura em graus celsius: ");
    scanf("%f",&c);
    f = c * 9/5 + 32;
    printf("\n Temperatura em fahrenheint: %f ",f);

    return 0;

}