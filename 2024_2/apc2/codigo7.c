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
    printf("Tamanho de inteiro = %ld\n",sizeof(int));
    printf("Tamanho de um char = %ld\n",sizeof(char));
    printf("Tamanho de um registro = %ld\n",sizeof(registro));

    return 0;
}