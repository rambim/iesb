#include <stdio.h>
#include <stdlib.h>


typedef struct registro
{
    char a;
    int b;
    char c;
    int d;
}registro;

int main()
{
    printf("\n Tamanho de int: %d",sizeof(int));
    printf("\n Tamanho de float: %d",sizeof(float));
    printf("\n Tamanho de char: %d",sizeof(char));
    printf("\n Tamanho de registro: %d",sizeof(registro));

    return 0;
}

