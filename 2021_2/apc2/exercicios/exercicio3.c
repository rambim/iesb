/*

Faça um programa que leia dois valores inteiros e chame uam função que receba
estes 2 valores de entrada e através da manipulação de seus endereços, faça  com que o maior
valor fique na primeira variável e o segundo valor fique na segunda viarável.

Mostre o conteúdo das variáveis antes e depois da chamada da função

*/

#include <stdio.h>
#include <stdlib.h>
void maior_na_primeira(int *tiozinho, int *tiazinha);

int main()
{

    int a = 2;
    int b = 10;
    int c = 2;
    int d = 10;

    maior_na_primeira(&a,&b);
    maior_na_primeira(&c,&d);

    printf("\n -> %d",a);
    printf("\n -> %d",b);
    printf("\n -> %d",c);
    printf("\n -> %d",d);

    printf("\n");
    return 0;
}

void maior_na_primeira(int *tiozinho, int *tiazinha)
{
    int aux;

    if (*tiazinha > *tiozinho)
    {
        aux = *tiazinha;
        *tiazinha = *tiozinho;
        *tiozinho = aux;
    }
}
