/*

Faça um programa que receba do usuário a idade em dias
e msotre em ano, meses, e dias

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int meses;
    int idade_expressa_dias;
    int anos;
    int dias;
    int resto;
    int resto2;
    printf("\n Digite sua idade expressa em dias: ");
    scanf("%d",&idade_expressa_dias);

    anos = idade_expressa_dias/365;
    resto = idade_expressa_dias % 365;
    meses = resto / 30;

    resto2 = resto % 30;

    printf("\n Anos: %d",anos);
    printf("\n Meses: %d",meses);
    printf("\n Dias: %d",resto2);

    printf("\n");

    return 0;

}