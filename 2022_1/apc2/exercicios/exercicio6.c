/*

Escreva uma função que receba dois números inteiros 
retorne o menor número

*/


#include <stdio.h>
#include <stdlib.h>


int ricardo(int n1, int n2);
int main()
{
    int n1,n2;
    int numero;

    printf("\n Digite n1: ");
    scanf("%d",&n1);
    printf("\n Digite n2: ");
    scanf("%d",&n2);

    numero = ricardo(n1,n2);

    printf("\n Numero: %d",numero);
    return 0;
}


int ricardo(int n1, int n2)
{
    if (n1<n2)
        return n1;
    else
        return n2;
}


