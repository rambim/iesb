#include <stdio.h>
#include <stdlib.h>


typedef struct registro
{
    int numero1;
    int numero2;
    float numero3;
    float numero4;
    char nome[10];
    int * ptr;
}registro;

int main()
{

    printf("\n Tamanho de um inteiro  : %ld",sizeof(int));
    printf("\n Tamanho de um float    : %ld",sizeof(float));
    printf("\n Tamanho de um char     : %ld",sizeof(char));
    printf("\n Tamanho de um registro : %ld",sizeof(registro));
    printf("\n");
    return 0;
}