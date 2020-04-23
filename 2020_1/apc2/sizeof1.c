#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x;
    char y;
    int vet_inteiros[10];

    int tamanho;

    tamanho = sizeof(int);
    printf("\n O tamanho de um inteiro e de %d bytes",tamanho);
    printf("\n");

    tamanho = sizeof(x);
    printf("\n O tamanho de X e de %d bytes",tamanho);
    printf("\n");

    tamanho = sizeof(char);
    printf("\n O tamanho de um char e de %d bytes",tamanho);
    printf("\n");

    tamanho = sizeof(y);
    printf("\n O tamanho de y e de %d bytes",tamanho);
    printf("\n");

    tamanho = sizeof(vet_inteiros);
    printf("\n O tamanho de vet_inteiros e de %d bytes",tamanho);
    printf("\n");

    return 0;


}