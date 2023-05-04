/*

Construa uma função que receba por parâmetro 2 números e retorne 1 caso o primeiro seja maior
que o segundo e retorne 2 caso o segundo seja maior que o primeiro.

Na sua função principal, leia 2 números e utilizando a função criada, mostre na tela
qual dos 2 números lidos é o maior


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;
    int retorno;

    printf("\n Digite n1: ");
    scanf("%d",&n1);
    printf("\n Digite N2: ");
    scanf("%d",&n2);

    retorno = maior(n1,n2);

    if (retorno == 1)
    {
        printf("\n %d eh maior que %d",n1,n2);
    }
    if (retorno == 2)
    {
        printf("\n %d eh maior que %d",n2,n1);
    }
        


    printf("\n");
    return 0;
}

int maior(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    if (b > a)
    {
        return 2;
    }
}
