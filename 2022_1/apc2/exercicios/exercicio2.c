/*
 Faça um programa que receba do usuário sua idade em anos, meses e dias
 e mostre essa idade apenas em dias. ano = 365, mes = 30

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anos, meses, dias;
    int dias_total;

    printf("\n Digite quantos anos voce tem: ");
    scanf("%d",&anos);

    printf("\n Digite quantos meses voce tem: ");
    scanf("%d",&meses);

    printf("\n Digite quantos dias voce tem: ");
    scanf("%d",&dias);

    dias_total = (anos*365) + (meses*30) + dias;

    printf("\n Total em dias: %d",dias_total);
   
    printf("\n");
    return 0;
}


