/*

Escreva um programa em C que leia 5 valores inteiros e imprima para
cada um o seu correspondente valor absoluto. Para obter o valor absoluto
do número utilize a função Absoluto especificada 

*/


#include <stdio.h>
#include <stdlib.h>

int absoluto(int n);

int main()
{
    int i;
    int numero,abs;

    for(i=0;i<5;i++)
    {
        printf("\n Digite o numero: ");
        scanf("%d",&numero);
        abs = absoluto(numero);
        printf("\n Numero absoluto: %d",abs);
    }
    printf("\n");
    return 0;
}

int absoluto(int n)
{
    if (n <0)
        n = n * (-1);
    
    return n;
}