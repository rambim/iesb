// 2 - Faça um programa que receba do usuário uma temperatura em graus Celsius e transforme em Firenhaint

#include <stdio.h>
#include <stdlib.h>


int main(int argc , char * argv[])
{
    float c, f;
    printf("\n Digite o valor em graus celsius: ");
    scanf("%f",&c);

    f = c * 9/5 + 32;

    printf("\n Temperatura em Firensdirughsidruh: %f",f);

    printf("\n");
    return 0;
}