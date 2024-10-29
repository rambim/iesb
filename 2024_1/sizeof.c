#include <stdio.h>

typedef struct registro
{
    char nome[55];
    int idade;
    double salario;
}registro;

int main()
{

    printf("O Tamanho de um int      em bytes = %ld\n",sizeof(int));
    printf("O Tamanho de um float    em bytes = %ld\n",sizeof(float));
    printf("O Tamanho de um char     em bytes = %ld\n",sizeof(char));
    printf("O Tamanho de um double   em bytes = %ld\n",sizeof(double));
    printf("O Tamanho de um registro em bytes = %ld\n",sizeof(registro));

    return 0;
}