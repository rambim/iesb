/*

Crie um programa que contenha uma funcao que permita passar por parametro dois 
numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e
armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera
modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal.

*/


#include <stdio.h>
#include <stdlib.h>

void funcao(int * jose, int b);

int main()
{
    int a = 2;
    int b = 3;

    printf("\n");

    printf("\n Antes da funcao: ");
    printf("\n -> A:%d",a);
    printf("\n -> B:%d",b);
    funcao(&a,b);    
    printf("\n Depois da funcao: ");
    printf("\n -> A:%d",a);
    printf("\n -> B:%d",b);
    printf("\n");
    return 0;
}

void funcao(int * jose, int b)
{
    *jose = *jose + b;
}

