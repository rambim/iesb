/*

Faça um programa que receba do usuario um número e mostre
seu sucessor e seu antecessor
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int ant,prox,numero;

    printf("\n Digite um numero: ");
    scanf("%d",&numero);
    ant = numero - 1;
    prox = numero + 1;

    printf("\n Antecessor: %d",ant);
    printf("\n Sucessor: %d",prox);
    return 0;
}