/*
Crie um programa que contenha uma funcao que permita passar por parametro dois 
numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e 
armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera
modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal.
*/


#include <stdio.h>
#include <stdlib.h>


void funcao(int * x, int y);

int main()
{
    int a,b;

    printf("\n Digite o valor de a: ");
    scanf("%d",&a);
    printf("\n Digite o valor de b: ");
    scanf("%d",&b);

    funcao(&a,b);

    printf("\n Resultado da soma: %d",a);

    printf("\n");
    return 0;
}

void funcao(int * x, int y)
{
    int soma;
    soma = *x + y;
    *x = soma;
}



