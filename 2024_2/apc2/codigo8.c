#include <stdio.h>
#include <stdlib.h>


typedef struct registro
{
    int valor;
    char letra;
    int cpf;
}registro;

int main()
{
    int * ptr;

    ptr = (int*)malloc(sizeof(int));

    *ptr = 2;

    printf("Conteudo de quem ptr aponta = %d\n",*ptr);

    return 0;
}